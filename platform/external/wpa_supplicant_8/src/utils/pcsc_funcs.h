/*
 * WPA Supplicant / PC/SC smartcard interface for USIM, GSM SIM
 * Copyright (c) 2004-2006, 2012, Jouni Malinen <j@w1.fi>
 * Copyright (c) 2011 Sony Ericsson Mobile Communications AB
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#ifndef PCSC_FUNCS_H
#define PCSC_FUNCS_H

/* GSM files
 * File type in first octet:
 * 3F = Master File
 * 7F = Dedicated File
 * 2F = Elementary File under the Master File
 * 6F = Elementary File under a Dedicated File
 */
#define SCARD_FILE_MF		0x3F00
#define SCARD_FILE_GSM_DF	0x7F20
#define SCARD_FILE_UMTS_DF	0x7F50
#define SCARD_FILE_GSM_EF_IMSI	0x6F07
#define SCARD_FILE_GSM_EF_AD	0x6FAD
#define SCARD_FILE_EF_DIR	0x2F00
#define SCARD_FILE_EF_ICCID	0x2FE2
#define SCARD_FILE_EF_CK	0x6FE1
#define SCARD_FILE_EF_IK	0x6FE2

#define SCARD_CURRENT_ADF	0x7FFF

#define SCARD_CHV1_OFFSET	13
#define SCARD_CHV1_FLAG		0x80

typedef enum {
	SCARD_GSM_SIM_ONLY,
	SCARD_USIM_ONLY,
	SCARD_TRY_BOTH
} scard_sim_type;


#if defined(PCSC_FUNCS) || defined(PCSC_FUNCS_SEMC)
#if defined(MULTI_SCARD)
struct scard_data * scard_init(scard_sim_type sim_type, char *socket, int slot);
#else
struct scard_data * scard_init(scard_sim_type sim_type, char *socket);
#endif
void scard_deinit(struct scard_data *scard);

int scard_set_pin(struct scard_data *scard, const char *pin);
int scard_get_imsi(struct scard_data *scard, char *imsi, size_t *len);
int scard_get_mnc_len(struct scard_data *scard);
int scard_gsm_auth(struct scard_data *scard, const unsigned char *_rand,
		   unsigned char *sres, unsigned char *kc);
int scard_umts_auth(struct scard_data *scard, const unsigned char *_rand,
		    const unsigned char *autn,
		    unsigned char *res, size_t *res_len,
		    unsigned char *ik, unsigned char *ck, unsigned char *auts);
int scard_get_pin_retry_counter(struct scard_data *scard);
int scard_supports_umts(struct scard_data *scard);

#else /* PCSC_FUNCS */

#define scard_init(s, r) NULL
#define scard_deinit(s) do { } while (0)
#define scard_set_pin(s, p) -1
#define scard_get_imsi(s, i, l) -1
#define scard_get_mnc_len(s) -1
#define scard_gsm_auth(s, r, s2, k) -1
#define scard_umts_auth(s, r, a, r2, rl, i, c, a2) -1
#define scard_get_pin_retry_counter(s) -1
#define scard_supports_umts(s) 0

#endif /* PCSC_FUNCS */

#endif /* PCSC_FUNCS_H */
