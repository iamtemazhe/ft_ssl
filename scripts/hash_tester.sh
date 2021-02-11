#!/bin/bash

GREEN='\033[1;32m'
RED='\033[1;31m'
DEFAULT='\033[0m'
ERR=$RED
SUCCESS=$GREEN

if [[ "$1" == "test" ]]; then
	hashes=(md5 sha224 sha512-224 sha256 sha512-256 sha384 sha512)
elif [[ "$1" == "valg" ]]; then
	valgrind --leak-check=full --track-origins=yes ${*:2}
	exit
else
	hashes=$1
fi

args=()
i0=2
for i in "${@:$i0}"; do
	if [[ "$i" == "-s" ]]; then
		flg_s=True
	elif [[ "$i" == "-i" ]]; then
		flg_i=True
	elif [[ "$i" == "-v" ]]; then
		flg_v=True
	else
		args+=($i)
	fi
done

for hash in "${hashes[@]}"; do
	for i in "${args[@]}"; do
		if [[ -n "${flg_s}" ]]; then
			raw_ssl=$(./ft_ssl $hash -s "$i")
			ssl=$(echo $raw_ssl | awk '{print $4}')
			raw_openssl=$(echo -n $i | openssl $hash)
		elif [[ -n "${flg_i}" ]]; then
			raw_ssl=$(./ft_ssl $hash $i)
			ssl=$(echo $raw_ssl | awk '{print $4}')
			raw_openssl=$(openssl $hash $i)
		else
			raw_ssl=$(echo -n $i | ./ft_ssl $hash)
			ssl=$raw_ssl
			raw_openssl=$(echo -n $i | openssl $hash)
			openssl=$(echo -n $i | openssl $hash | awk '{print $2}')
		fi

		openssl=$(echo $raw_openssl | awk '{print $2}')

		if [[ -n "${flg_v}" ]]; then
			echo "[ft_ssl]  $raw_ssl"
			echo "[openssl] $raw_openssl"
		fi

		diff=$(diff <(echo $ssl) <(echo $openssl))
		if [ -z "${diff}" ]; then
			echo -e $GREEN"[$hash: $i] Success:\n$ssl"$DEFAULT
		else
			echo -e $ERR"[$hash] Failure:\n$diff"$DEFAULT
		fi
	done
done
