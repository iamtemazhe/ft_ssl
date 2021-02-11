#!/bin/bash

exec 5>&2
exec 2>/dev/null

GREEN='\033[1;32m'
RED='\033[1;31m'
DEFAULT='\033[0m'
ERR=$RED
SUCCESS=$GREEN

KEY_SIZE=24
IV_SIZE=8
SALT_SIZE=8
PASS_SIZE=12

i0=2
args=()
fh="-m"
oh="-md"

HASH="sha256"
hashes=($HASH)

fssl_file_e="test_ft_ssl"
ossl_file_e="test_openssl"

fssl_file_d=$fssl_file_e"_d"
ossl_file_d=$ossl_file_e"_d"

if [[ "$1" == "test" ]]; then
	ciphers=(base64 des-ecb des-cbc des-cfb des-ofb des-ede3-ecb des-ede3-cbc des-ede3-cfb des-ede3-ofb)
elif [[ "$1" == "valg" ]]; then
	exec 2>&5
	valgrind --leak-check=full --track-origins=yes ${*:2}
	exit
else
	ciphers=$1
fi

for i in "${@:$i0}"; do
	if [[ -n "${cont}" ]]; then
		if [[ "$cont" == "-p" ]]; then
			s="-S"
			fp="-p"
			op="-pass"
			PASS=$i
			if [[ "$PASS" == "rand" ]]; then
				PASS=$(./ft_ssl rand -x $PASS_SIZE)
			fi
			if [[ -z "${SALT}" ]]; then
				SALT=$(./ft_ssl rand -x $SALT_SIZE)
			fi
			FPASS="$PASS"
			OPASS="pass:$PASS"
		elif [[ "$cont" == "-ps" ]]; then
			PASS_SIZE=$i
		elif [[ "$cont" == "-ks" ]]; then
			KEY_SIZE=$i
		elif [[ "$cont" == "-ivs" ]]; then
			IV_SIZE=$i
		elif [[ "$cont" == "-n" ]]; then
			fn="-n"
			on="-iter"
			ITER=$i
		elif [[ "$cont" == "-k" ]]; then
			k="-K"
			KEY=$i
		elif [[ "$cont" == "-s" ]]; then
			s="-S"
			SALT=$i
		elif [[ "$cont" == "-v" || "$cont" == "-iv" ]]; then
			fv="-v"
			ov="-iv"
			IV=$i
		elif [[ "$cont" == "-m" || "$cont" == "-md" ]]; then
			HASH=$i
			if [[ "$HASH" == "test" ]]; then
				hashes=(md5 sha224 sha512-224 sha256 sha512-256 sha384 sha512)
			else
				hashes=($HASH)
			fi
		fi
		cont=""
		continue
	fi

	if [[ "$i" == "-d" ]]; then
		flg_d=True
	elif [[ "$i" == "-i" ]]; then
		flg_i=True
	elif [[ "$i" == "-a" ]]; then
		a="-a"
	elif [[ "$i" == "-c" ]]; then
		nopad_fssl="-c"
		nopad_ossl="-nopad"
		nopad_fssl_d=$nopad_fssl
		nopad_ossl_d=$nopad_ossl
	elif [[ "$i" == "-cc" ]]; then
		nopad_fssl="-c"
		nopad_ossl="-nopad"
	elif [[ "$i" == "-f" || "$i" == "-pbkdf2" ]]; then
		kdf_fssl="-f"
		kdf_ossl="-pbkdf2"
	elif [[ "$i" == "-w" || "$i" == "-P" ]]; then
		flg_w=True
	elif [[ "$i" == "-debug" ]]; then
		debug=True
	elif [[ "$i" == "-p"  ||  "$i" == "-k" || "$i" == "-iv"  || "$i" == "-s"  ||\
			"$i" == "-ps" || "$i" == "-ks" || "$i" == "-ivs" || "$i" == "-ss" ||\
			"$i" == "-v"  || "$i" == "-m"  || "$i" == "-md"  || "$i" == "-n" ]]; then
		cont=$i
	elif [[ "$i" == "-err" ]]; then
		exec 2>&5
	else
		args+=($i)
	fi
done

if [[ -z "${PASS}" ]]; then
	k="-K"
	fv="-v"
	ov="-iv"
	if [[ -z "${KEY}" ]]; then
		KEY=$(./ft_ssl rand -x $KEY_SIZE)
	fi
	if [[ -z "${IV}" ]]; then
		IV=$(./ft_ssl rand -x $IV_SIZE)
	fi
fi

echo "*************************************************************************"
if [[ -n "${PASS}" ]]; then
	echo -e "Pass: $PASS"
fi
if [[ -n "${SALT}" ]]; then
	echo -e "Salt: $SALT"
fi
if [[ -n "${KEY}" ]]; then
	echo -e "Key:  $KEY"
fi
if [[ -n "${IV}" ]]; then
	echo -e "IV:   $IV"
fi
echo "*************************************************************************"

for cipher in "${ciphers[@]}"; do
	for hash in "${hashes[@]}"; do
		for i in "${args[@]}"; do
			if [[ -n "${flg_w}" ]]; then
				if [[ "$cipher" == "base64" ]]; then
					continue
				fi
				echo -e "\n[$cipher: $i]"
				echo -e "[ft_ssl]\n$(./ft_ssl $cipher -w $fp $FPASS $s $SALT $k $KEY $fv $IV $a -i  $i $nopad_fssl $kdf_fssl $fh $hash $fn $ITER $err_off)"
				echo -e "[openssl]\n$(openssl $cipher -P $op $OPASS $s $SALT $k $KEY $ov $IV $a -in $i $nopad_ossl $kdf_ossl $oh $hash $on $ITER $err_off)"
				continue
			fi
			if [[ -n "${flg_i}" ]]; then
				ssl=$(./ft_ssl    $cipher $fp $FPASS $s $SALT $k $KEY $fv $IV $a -i  $i -o   $fssl_file_e $fh $hash $nopad_fssl $kdf_fssl $fn $ITER $err_off)
				openssl=$(openssl $cipher $op $OPASS $s $SALT $k $KEY $ov $IV $a -in $i -out $ossl_file_e $oh $hash $nopad_ossl $kdf_ossl $on $ITER $err_off)
			else
				ssl=$(echo $i | ./ft_ssl    $cipher $fp $FPASS $s $SALT $k $KEY $fv $IV $a -o   $fssl_file_e $fh $hash $nopad_fssl $kdf_fssl $fn $ITER $err_off)
				openssl=$(echo $i | openssl $cipher $op $OPASS $s $SALT $k $KEY $ov $IV $a -out $ossl_file_e $oh $hash $nopad_ossl $kdf_ossl $on $ITER $err_off)
			fi
			if [[ -n "${debug}" ]]; then
				echo "[ft_ssl]  encrypted: $(cat -e $fssl_file_e)"
				echo "[openssl] encrypted: $(cat -e $ossl_file_e)"
			fi
			if [[ -n "${flg_d}" ]]; then
				ssl=$(./ft_ssl    $cipher -d $fp $FPASS $s $SALT $k $KEY $fv $IV $a -i  $fssl_file_e -o   $fssl_file_d $fh $hash $nopad_fssl_d $kdf_fssl $fn $ITER $err_off)
				openssl=$(openssl $cipher -d $op $OPASS $s $SALT $k $KEY $ov $IV $a -in $ossl_file_e -out $ossl_file_d $oh $hash $nopad_ossl_d $kdf_ossl $on $ITER $err_off)

				if [[ -n "${debug}" ]]; then
					echo "[ft_ssl]  decrypted: $(cat -e $fssl_file_d)"
					echo "[openssl] decrypted: $(cat -e $ossl_file_d)"
				fi
				ssl_file=$fssl_file_d
				openssl_file=$ossl_file_d
			else
				ssl_file=$fssl_file_e
				openssl_file=$ossl_file_e
			fi
			diff=$(diff $ssl_file $openssl_file)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[$cipher: $i][$hash] Success!"$DEFAULT
			else
				echo -e $ERR"[$cipher: $i][$hash] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_file_e $ossl_file_e $fssl_file_d $ossl_file_d
		done
	done
done
