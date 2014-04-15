/*
 * GSM home network domain configuration data
 * Copyright (c) 2012 Sony Mobile Communications AB
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef GSM_DOMAIN_H
#define GSM_DOMAIN_H

/**
 * struct wpa_gsm_domain - GSM home network domain configuration data
 *
 * This structure contains configuration data for a GSM home network domain.
 */
struct wpa_gsm_domain {
	/**
	* next - Next GSM home network domain in the list
	*
	* This pointer can be used to iterate over all GSM home network domains.
	* The head of this list is stored in the gsm_domain field of
	* struct wpa_config.
	*/
	struct wpa_gsm_domain *next;

	/**
	* mcc - Mobile country code
	*/
	int mcc;

	/**
	* mnc - Mobile network code
	*/
	int mnc;

	/**
	* domain - GSM home network domain for a given country & network codes
	*
	* Domain part in permanent identity will be replaced to this string if
	* mcc & mnc codes matches the ones obtained from the SIM card.
	*/
	char *domain;
};

#endif /* GSM_DOMAIN_H */
