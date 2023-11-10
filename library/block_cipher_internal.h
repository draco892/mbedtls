/**
 * \file block_cipher_internal.h
 *
 * \brief Lightweight abstraction layer for block ciphers with 128 bit blocks,
 * for use by the GCM and CCM modules.
 */
/*
 *  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */
#ifndef MBEDTLS_BLOCK_CIPHER_INTERNAL_H
#define MBEDTLS_BLOCK_CIPHER_INTERNAL_H

#include "mbedtls/build_info.h"

#include "mbedtls/cipher.h"

#include "mbedtls/block_cipher.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief           Initialize the context.
 *                  This must be the first API call before using the context.
 *
 * \param ctx       The context to initialize.
 */
static inline void mbedtls_block_cipher_init(mbedtls_block_cipher_context_t *ctx)
{
    memset(ctx, 0, sizeof(*ctx));
}

/**
 * \brief           Set the block cipher to use with this context.
 *                  This must be called after mbedtls_block_cipher_init().
 *
 * \param ctx       The context to set up.
 * \param cipher_id The identifier of the cipher to use.
 *                  This must be either AES, ARIA or Camellia.
 *                  Warning: this is a ::mbedtls_cipher_id_t,
 *                  not a ::mbedtls_block_cipher_id_t!
 *
 * \retval          \c 0 on success.
 * \retval          #MBEDTLS_ERR_CIPHER_BAD_INPUT_DATA if \p cipher_id was
 *                  invalid.
 */
int mbedtls_block_cipher_setup(mbedtls_block_cipher_context_t *ctx,
                               mbedtls_cipher_id_t cipher_id);

/**
 * \brief           Clear the context.
 *
 * \param ctx       The context to clear.
 */
void mbedtls_block_cipher_free(mbedtls_block_cipher_context_t *ctx);

#ifdef __cplusplus
}
#endif

#endif /* MBEDTLS_BLOCK_CIPHER_INTERNAL_H */
