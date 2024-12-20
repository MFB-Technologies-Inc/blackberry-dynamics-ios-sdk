/*
 * (c) 2018 BlackBerry Limited. All rights reserved.
 *
 */

#pragma once

#import <Foundation/Foundation.h>

/** Constant key value for application server configuration.\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyServers;

/** Constant key value for application-specific configuration data.\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyConfig;

/** Constant key value for the Data Leakage security policy indicator.\ See
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyPreventDataLeakageOut;

/** Constant key value for the Data Leakage security policy indicator.\ See
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyPreventDataLeakageIn;

/** Constant key value for enabling and disabling detailed diagnostic
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyDetailedLogsOn;

/** Constant key value for allowing and disallowing users from enabling detailed
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyPreventUserDetailedLogs;

/** Constant key value for the user's enterprise email address.\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyUserId;

/** Constant key value for the user's User Principal Name (UPN).\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyUserPrincipalName;

/** Constant key value for application instance identifier.\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyInstanceIdentifier;

/** Constant key for AI Writing Tools security policy indicator.\  See
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyAllowAiWritingTools;

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
/**
 * \if iOS
 * Constant key value for whether dictation input is allowed.\ See under
 * \ref GDiOS::getApplicationConfig.
 * \endif
 */
extern const NSString* const GDAppConfigKeyPreventDictation;

/**
 * \if iOS
 * Constant key value for whether wearable (WatchOS) devices are allowed.\ See under
 * \ref GDiOS::getApplicationConfig.
 * \endif
 */
extern const NSString* const GDAppConfigKeyAllowWearable;

/**
 * \if iOS
 * Constant key value for whether custom keyboards are allowed.\ See under
 * \ref GDiOS::getApplicationConfig.
 * \endif
 */
extern const NSString* const GDAppConfigKeyPreventCustomKeyboards;

/**
 * \if iOS
 * Constant key value for whether screen recording and sharing is allowed.\ See under
 * \ref GDiOS::getApplicationConfig.
 * \endif
 */
extern const NSString* const GDAppConfigKeyPreventScreenRecording;

#endif

/** Constant key value for whether the application is protected by a BlackBerry
 *  Dynamics password.\ See under
 *  \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyProtectedByPassword;

/** Constant key value for whether BlackBerry Enterprise Identity is setup.
 */
extern const NSString* const GDAppEnterpriseIdActivated;

/** Constant key value containing a JSON array of available features.
 */
extern const NSString* const GDAppConfigKeyEnterpriseIdFeatures;

/** Constant key value for extra information from the management
 *  console.\ See under \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyExtraInfo;

/** \defgroup GDProtocols Secure Communication Protocols
 * \copydetails ssGDProtocols
 *
 * \{
 */

/** Constant key value for the list of communications protocols allowed by the
 *  enterprise.\ See under \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDAppConfigKeyCommunicationProtocols;

/** Constant value for a secure communication protocol: TLS version 1.0.\ See
 *  under \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDProtocolsKeyTLSv1_0;

/** Constant value for a secure communication protocol: TLS version 1.1.\ See
 *  under \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDProtocolsKeyTLSv1_1;

/** Constant value for a secure communication protocol: TLS version 1.2.\ See
 *  under \ref \ss_iOS_Mac{GDiOS,GDMac}::getApplicationConfig.
 */
extern const NSString* const GDProtocolsKeyTLSv1_2;

/** \}
 */

//TODO add proper documentation and possibly relocate
extern const NSString* const BBDWatchErrorDomain;
extern const NSString* const BBDWatchErrorKey;

