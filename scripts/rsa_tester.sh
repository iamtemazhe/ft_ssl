#!/bin/bash

GREEN='\033[1;32m'
RED='\033[1;31m'
DEFAULT='\033[0m'
ERR=$RED
SUCCESS=$GREEN

args=()
i0=2
ITER=1
PASS_SIZE=12

ciphertext_file="test_ciphertext_file"
key_file="test_rsa_key"
pkey_file="test_rsa_pkey"
fssl_key="test_ft_ssl_rsa_key"
ossl_key="test_openssl_rsa_key"

ciphers=(des-cbc des-cfb des-ofb des-ede3-cbc des-ede3-cfb des-ede3-ofb)
formats=(PEM DER)

if [[ "$1" == "valg" ]]; then
	valgrind --leak-check=full --track-origins=yes ${*:2}
	exit
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
		elif [[ "$cont" == "-ps" ]]; then
			PASS_SIZE=$i
		elif [[ "$cont" == "-i" ]]; then
			ITER=$i
		fi
		cont=""
		continue
	fi

	if [[ "$i" == "-p"  || "$i" == "-ps" || "$i" == "-i" ]]; then
		cont=$i
	elif [[ "$i" == "-err" ]]; then
		flg_err=True
	else
		args+=($i)
	fi
done

if [[ -z "${PASS}" ]]; then
	PASS=$(./ft_ssl rand -x $PASS_SIZE)
fi
echo "*************************************************************************"
echo -e "Pass: $PASS"
echo "*************************************************************************"
FPASS="$PASS"
OPASS="pass:$PASS"

if [[ "$1" == "genrsa" || "$1" == "rsa" ]]; then
	# rsa
	for i in $(seq 1 $ITER); do
		echo -e "\nTest $i"

		echo "*************************************************************************"
		ssl=$(./ft_ssl genrsa -out $key_file)
		echo -e "$(cat $key_file)"
		echo "*************************************************************************"

		if [[ -z "${flg_err}" ]]; then
			exec 5>&2
			exec 2>/dev/null
		fi

		# genrsa check key text&modulus
		ssl=$(./ft_ssl genrsa -in $key_file -out $fssl_key -modulus -text)
		openssl=$(openssl rsa -in $key_file -out $ossl_key -modulus -text)
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[genrsa private key text] Success!"$DEFAULT
		else
			echo -e $ERR"[genrsa private key text] Failure:\n$diff"$DEFAULT
		fi
		rm -f $fssl_key $ossl_key

		# rsa check key
		ssl=$(./ft_ssl    rsa -in $key_file -out $fssl_key -check -modulus -text)
		openssl=$(openssl rsa -in $key_file -out $ossl_key -check -modulus -text)
		echo -e "$(cat $ossl_key)"
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[rsa private key check&text] Success!"$DEFAULT
		else
			echo -e $ERR"[rsa private key check&text] Failure:\n$diff"$DEFAULT
		fi
		rm -f $fssl_key $ossl_key

		# key formats
		for form in "${formats[@]}"; do
			ssl=$(./ft_ssl    rsa -in $key_file -out $fssl_key -outform $form)
			openssl=$(openssl rsa -in $fssl_key -out $ossl_key -inform $form)
			diff=$(diff $key_file $ossl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[private key outform: $form] Success!"$DEFAULT
			else
				echo -e $ERR"[private key outform: $form] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		# key formats
		for form in "${formats[@]}"; do
			openssl=$(openssl rsa -in $key_file -out $ossl_key -outform $form)
			ssl=$(./ft_ssl    rsa -in $ossl_key -out $fssl_key -inform $form)
			diff=$(diff $key_file $fssl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[private key inform: $form] Success!"$DEFAULT
			else
				echo -e $ERR"[private key inform: $form] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		# key e des
		for cipher in "${ciphers[@]}"; do
			ssl=$(./ft_ssl    rsa -in $key_file -out $fssl_key -passout $FPASS -$cipher)
			# echo -e "$(cat $fssl_key)"
			openssl=$(openssl rsa -in $fssl_key -out $ossl_key -passin $OPASS)
			# echo -e "$(cat $ossl_key)"
			diff=$(diff $key_file $ossl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[private key encrypt: $cipher] Success!"$DEFAULT
			else
				echo -e $ERR"[private key encrypt: $cipher] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		# key d des
		for cipher in "${ciphers[@]}"; do
			openssl=$(openssl rsa -in $key_file -out $ossl_key -passout $OPASS -$cipher)
			# echo -e "$(cat $ossl_key)"
			ssl=$(./ft_ssl    rsa -in $ossl_key -out $fssl_key -passin $FPASS)
			# echo -e "$(cat $fssl_key)"
			diff=$(diff $key_file $fssl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[private key decrypt: $cipher] Success!"$DEFAULT
			else
				echo -e $ERR"[private key decrypt: $cipher] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		# pkey out
		ssl=$(./ft_ssl    rsa -in $key_file -out $fssl_key -pubout)
		openssl=$(openssl rsa -in $key_file -out $ossl_key -pubout)
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[rsa construct public key] Success!"$DEFAULT
		else
			echo -e $ERR"[rsa construct public key] Failure:\n$diff"$DEFAULT
		fi
		cp -f $fssl_key $pkey_file
		rm -f $fssl_key $ossl_key

		# pkey in
		ssl=$(./ft_ssl    rsa -in $pkey_file -out $fssl_key -pubin -modulus -text)
		openssl=$(openssl rsa -in $pkey_file -out $ossl_key -pubin -modulus -text)
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[rsa public key text] Success!"$DEFAULT
		else
			echo -e $ERR"[rsa public key text] Failure:\n$diff"$DEFAULT
		fi
		rm -f $fssl_key $ossl_key

		# pkey e des
		for cipher in "${ciphers[@]}"; do
			ssl=$(./ft_ssl    rsa -in $pkey_file -out $fssl_key -pubin -passout $FPASS -$cipher)
			# echo -e "$(cat $fssl_key)"
			openssl=$(openssl rsa -in $fssl_key  -out $ossl_key -pubin -passin $OPASS)
			# echo -e "$(cat $ossl_key)"
			diff=$(diff $pkey_file $ossl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[public key encrypt: $cipher] Success!"$DEFAULT
			else
				echo -e $ERR"[public key encrypt: $cipher] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		# pkey d des
		for cipher in "${ciphers[@]}"; do
			ssl=$(./ft_ssl rsa -in $pkey_file -out $ossl_key -pubin -passout $FPASS -$cipher)
			# echo -e "$(cat $ossl_key)"
			ssl=$(./ft_ssl rsa -in $ossl_key  -out $fssl_key -pubin -passin $FPASS)
			# echo -e "$(cat $fssl_key)"
			diff=$(diff $pkey_file $fssl_key)
			if [ -z "${diff}" ]; then
				echo -e $GREEN"[public key decrypt: $cipher] Success!"$DEFAULT
			else
				echo -e $ERR"[public key decrypt: $cipher] Failure:\n$diff"$DEFAULT
			fi
			rm -f $fssl_key $ossl_key
		done

		if [[ -z "${flg_err}" ]]; then
			exec 2>&5
		fi

		rm -f $key_file $pkey_file
	done
elif [[ "$1" == "rsautl" || "$1" == "breakrsa" ]]; then
	# rsautl tests
	for i in "${args[@]}"; do
		echo -e "\nTest $i"

		echo "*************************************************************************"
		ssl=$(./ft_ssl genrsa -out $key_file)
		echo -e "$(cat $key_file)"
		echo "*************************************************************************"

		if [[ -z "${flg_err}" ]]; then
			exec 5>&2
			exec 2>/dev/null
		fi

		# pkey out
		ssl=$(./ft_ssl    rsa -in $key_file -out $fssl_key -pubout)
		openssl=$(openssl rsa -in $key_file -out $ossl_key -pubout)
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[rsa construct public key] Success!"$DEFAULT
		else
			echo -e $ERR"[rsa construct public key] Failure:\n$diff"$DEFAULT
		fi
		cp -f $fssl_key $pkey_file
		rm -f $fssl_key $ossl_key

		# rsautl key
		ssl=$(./ft_ssl rsautl -in $i -inkey $key_file -out $fssl_key -e)
		# echo -e "$(cat $fssl_key)"
		ssl=$(./ft_ssl rsautl -in $fssl_key -inkey $key_file -out $ossl_key -d)
		# echo -e "$(cat $ossl_key)"
		diff=$(diff $i $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[encrypt-decrypt: $i] Success!"$DEFAULT
		else
			echo -e $ERR"[encrypt-decrypt: $i] Failure:\n$diff"$DEFAULT
		fi
		rm -f $fssl_key $ossl_key

		# rsautl pkey
		ssl=$(./ft_ssl rsautl -in $i -inkey $pkey_file -out $fssl_key -pubin -e)
		# echo -e "$(cat $fssl_key)"
		ssl=$(./ft_ssl rsautl -in $fssl_key -inkey $key_file -out $ossl_key -d)
		# echo -e "$(cat $ossl_key)"
		diff=$(diff $i $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[encrypt-decrypt: $i] Success!"$DEFAULT
		else
			echo -e $ERR"[encrypt-decrypt: $i] Failure:\n$diff"$DEFAULT
		fi
		cp -f $fssl_key $ciphertext_file
		rm -f $fssl_key $ossl_key

		# rsa breaker
		ssl=$(./ft_ssl rsa -in $key_file -t -n -o $ossl_key)
		# echo -e "$(cat $ossl_key)"
		# echo -e "$(cat $i)"
		# echo -e "$(cat $ciphertext_file)"
		cp $pkey_file "pkey"
		cp $ciphertext_file "ciphertext_file"
		ssl=$(./ft_ssl breakrsa -i $ciphertext_file -o $fssl_key -ko $ossl_key $pkey_file)
		diff=$(diff $i $fssl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[breakrsa text: $i] Success!"$DEFAULT
		else
			echo -e $ERR"[breakrsa text: $i] Failure:\n$diff"$DEFAULT
		fi
		diff=$(diff $key_file $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[breakrsa key: $i] Success!"$DEFAULT
		else
			echo -e $ERR"[breakrsa key: $i] Failure:\n$diff"$DEFAULT
		fi

		if [[ -z "${flg_err}" ]]; then
			exec 2>&5
		fi

		rm -f $fssl_key $ossl_key $key_file $pkey_file $ciphertext_file
	done
elif [[ "$1" == "dsa" || "$1" == "gendsa" ]]; then
	# gendsa
	for i in $(seq 1 $ITER); do
		echo -e "\nTest $i"

		echo "*************************************************************************"
		ssl=$(./ft_ssl gendsa -out $key_file -modulus -text)
		echo -e "$(cat $key_file)"
		echo "*************************************************************************"

		if [[ -z "${flg_err}" ]]; then
			exec 5>&2
			exec 2>/dev/null
		fi

		# gendsa check key text&modulus
		ssl=$(./ft_ssl gendsa -in $key_file -out $fssl_key -modulus -text)
		openssl=$(openssl dsa -in $key_file -out $ossl_key -modulus -text)
		diff=$(diff $fssl_key $ossl_key)
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[gendsa private key text] Success!"$DEFAULT
		else
			echo -e $ERR"[gendsa private key text] Failure:\n$diff"$DEFAULT
		fi
		rm -f $fssl_key $ossl_key

		if [[ -z "${flg_err}" ]]; then
			exec 2>&5
		fi

		rm -f $fssl_key $ossl_key $key_file $pkey_file
	done
fi
