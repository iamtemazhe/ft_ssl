# ft_ssl
ft_ssl is a C pet-project from 42 course written in order to know more about
cryptography and security. Some standard, cipher and hashing OPENSSL's commands
are recoded here. Its output is compatible with OPENSSL's one.
RSA & DSA realized as 64-bit key long version.

## Installation

```bash
make
```

## Usage

```bash

./ft_ssl command [command opts] [command args]
./ft_ssl sha512 doc.txt -o hash.txt
./ft_ssl base64 -i doc.txt -o based_doc.txt
./ft_ssl des3 -e -i plain.txt -o crypto.txt -p SuperSecurePassword
./ft_ssl genrsa
```

## Available commands

#### Hash commands
* md5
* sha224
* sha256
* sha384
* sha512
* sha512-224
* sha512-256
#### Cipher commands
* base64
* des
* des-ecb
* des-cbc
* des-cfb
* des-ofb
* des3
* des-ede3-ecb
* des-ede3-cbc
* des-ede3-cfb
* des-ede3-ofdb
#### Standard commands
* help
* hexdump
* rand
* prime
* genrsa
* rsa
* rsautl
* breakrsa
* gendsa
