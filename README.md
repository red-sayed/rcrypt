# 🔑 rcrypt [![](https://img.shields.io/apm/l/vim-mode)](https://github.com/Red-company/RES_Implementation/blob/main/LICENSE.md)

> ‼️ *Patenting in process.* Don't try to steal or you'll lose your money.

<img src="https://github.com/red-sayed/rcrypt/blob/main/Screenshots/rcrypt_main.png?raw=true" style="object-fit:contain;
            width:auto;
            height:520px;">
            
## What is it?

This repository was used to conceive and implement _rcrypt_ encryption+hashing algorithm.<br/>
_rcrypt_ was made to encrypt/hash information(specifically passwords) with pretty bad performance.<br/>

It is also a part of [_RedLibrary_](https://github.com/Red-company/RedLibrary).

## What about speed?

It's about _1088.5x - 2350.7x_ speed down, comparing to [_Sha256_](https://github.com/red-sayed/Sha256) algorithm.

* [_Sha256 speed test_](https://github.com/Red-Laboratory/exp1_sha256-speedtest)
* [_rcrypt speed test_](https://github.com/Red-Laboratory/exp2_rcrypt-speedtest)

## How to use it?

All functions are in _'rcrypt.h'_.

```C
//
// Rcrypt -512 bits-
//
    
/**
 * @brief rcrypt512_enc
 *
 * @param key Key.
 * @param str Information to be locked.
 */
inline void rcrypt512_enc(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt512_dec
 *
 * @param key Key.
 * @param str Information to be unlocked.
 */
inline void rcrypt512_dec(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt512_hash
 *
 * @param key Key.
 * @param str Information to be encrypted and hashed after that.
 *
 * @return Pointer to a new string with hash.
 */
inline std::string * rcrypt512_hash(std::string_view key, std::string_view str) {...}


//
// Rcrypt -1024 bits-
//

/**
 * @brief rcrypt1024_enc
 *
 * @param key Key.
 * @param str Information to be locked.
 */
inline void rcrypt1024_enc(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt1024_dec
 *
 * @param key Key.
 * @param str Information to be unlocked.
 */
inline void rcrypt1024_dec(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt1024_hash
 *
 * @param key Key.
 * @param str Information to be encrypted and hashed after that.
 *
 * @return Pointer to a new string with hash.
 */
inline std::string * rcrypt1024_hash(std::string_view key, std::string_view str) {...}


//
// Rcrypt -1536 bits-
//

/**
 * @brief rcrypt1536_enc
 *
 * @param key Key.
 * @param str Information to be locked.
 */
inline void rcrypt1536_enc(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt1536_dec
 *
 * @param key Key.
 * @param str Information to be unlocked.
 */
inline void rcrypt1536_dec(std::string_view key, std::string *str) {...}

/**
 * @brief rcrypt1536_hash
 *
 * @param key Key.
 * @param str Information to be encrypted and hashed after that.
 *
 * @return Pointer to a new string with hash.
 */
inline std::string * rcrypt1536_hash(std::string_view key, std::string_view str) {...}
```

**Tech notes:**
 * Padding is provided only for _"in"_ params. Key length(in bytes) is calculated using the formula:<br/> _`KEY_LENGTH / 8`_.
 * This library is designed for small code size and simplicity, intended for cases where small binary size, low memory footprint and portability is more important than high performance.

**Notes:**
 * If you want to route result of encryption to _`std::cout`_, you should convert string to hexadecimal system, in other way you will get bad output!
 * There is no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

## Screenshots? Here they are:

Here's an example of encryption in _rcrypt512_ mode:

<img src="https://github.com/red-sayed/rcrypt/blob/main/Screenshots/rcrypt_1.png?raw=true" style="object-fit:contain;
            width:auto;
            height:520px;">

And the following one is the decryption of previous message:

<img src="https://github.com/red-sayed/rcrypt/blob/main/Screenshots/rcrypt_2.png?raw=true" style="object-fit:contain;
            width:auto;
            height:520px;">

##
All material in this repository is in the public domain.<br/>
With _**Copyright© ∞ [Vladimir Rogozin](https://github.com/red-sayed).**_
