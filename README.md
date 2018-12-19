Block Cipher Modes of Operation
===============================

Implementation of several modes of operation for block ciphers in C. Visit the [wikipedia article](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation) and the [NIST Special Publication 800-38A](https://nvlpubs.nist.gov/nistpubs/legacy/sp/nistspecialpublication800-38a.pdf) for more info.

To compile use `make`:

```
make release
```

See available options with `./bcm -h`:

```
Usage: ./bcm [options]
Options:
        -c block-cipher : cipher algorithm (default: null)
        -d              : decrypt
        -e              : encrypt
        -i iv           : initialization vector
        -k key          : private key
        -m mode         : mode of operation (default: ecb)
        -r file         : input file to encrypt/decrypt
        -w file         : output file
        -h              : this help

```

Example:

```
./bcm -m cbc -c aes -k 8e73b0f7da0e6452c810f32b809079e562f8ead2522c6b7b -i 000102030405060708090a0b0c0d0e0f -r plaintext -w ciphertext -e
```
