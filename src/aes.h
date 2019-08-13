/*
 *  FIPS-197 compliant AES implementation
 *
 *  Copyright (C) 2006-2007  Christophe Devine
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    * Redistributions of source code _must_ retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form may or may not reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *    * Neither the name of XySSL nor the names of its contributors may be
 *      used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 /* AES block cipher implementation from XYSSL */

#ifndef XYSSL_AES_H
#define XYSSL_AES_H

#define AES_ENCRYPT     1
#define AES_DECRYPT     0

/**
 * \brief          AES context structure
 */
typedef struct
{
    int nr;                     /*!<  number of rounds  */
    uint32_t *rk;          /*!<  AES round keys    */
    uint32_t buf[68];      /*!<  unaligned data    */
}
aes_context;

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * \brief          AES key schedule (encryption)
     *
     * \param ctx      AES context to be initialized
     * \param key      encryption key
     * \param keysize  must be 128, 192 or 256
     */
    void aes_setkey_enc(aes_context *ctx, const unsigned char *key,
        int keysize);

    /**
     * \brief          AES key schedule (decryption)
     *
     * \param ctx      AES context to be initialized
     * \param key      decryption key
     * \param keysize  must be 128, 192 or 256
     */
    void aes_setkey_dec(aes_context *ctx, const unsigned char *key,
        int keysize);

    /**
     * \brief          AES-ECB block encryption/decryption
     *
     * \param ctx      AES context
     * \param mode     AES_ENCRYPT or AES_DECRYPT
     * \param input    16-byte input block
     * \param output   16-byte output block
     */
    void aes_crypt_ecb(aes_context *ctx,
        int mode,
        const unsigned char input[16],
        unsigned char output[16]);

    /**
     * \brief          AES-CBC buffer encryption/decryption
     *
     * \param ctx      AES context
     * \param mode     AES_ENCRYPT or AES_DECRYPT
     * \param length   length of the input data
     * \param iv       initialization vector (updated after use)
     * \param input    buffer holding the input data
     * \param output   buffer holding the output data
     */
    void aes_crypt_cbc(aes_context *ctx,
        int mode,
        int length,
        unsigned char iv[16],
        const unsigned char *input,
        unsigned char *output);

    /**
     * \brief          AES-CFB buffer encryption/decryption
     *
     * \param ctx      AES context
     * \param mode     AES_ENCRYPT or AES_DECRYPT
     * \param length   length of the input data
     * \param iv_off   offset in IV (updated after use)
     * \param iv       initialization vector (updated after use)
     * \param input    buffer holding the input data
     * \param output   buffer holding the output data
     */
    void aes_crypt_cfb(aes_context *ctx,
        int mode,
        int length,
        int *iv_off,
        unsigned char iv[16],
        const unsigned char *input,
        unsigned char *output);

    /**
     * \brief          Checkup routine
     *
     * \return         0 if successful, or 1 if the test failed
     */
    int aes_self_test(int verbose);

#ifdef __cplusplus
}
#endif

#endif /* aes.h */