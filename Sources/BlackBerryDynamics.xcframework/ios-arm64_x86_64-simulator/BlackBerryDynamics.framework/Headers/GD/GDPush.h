/*
 * Copyright 2023 BlackBerry Limited. All rights reserved.
 *
 */

#ifndef __GD_PUSH_H__
#define __GD_PUSH_H__

#import <Foundation/Foundation.h>

// See: http://clang.llvm.org/docs/LanguageExtensions.html
/* \cond DOXYGEN_IGNORE */
#ifndef __has_extension
#define __has_extension(x) 0  // Compatibility with non-clang compilers.
#endif
/* \endcond */

/* \cond DOXYGEN_IGNORE */
#if __has_extension(attribute_deprecated_with_message)
#   define DEPRECATE_PUSH_CONNECT_DISCONNECT __attribute__((deprecated("No longer required")))
#   define DEPRECATE_GDPUSHCONNECTION __attribute__((deprecated("GDPushConnection interface has been deprecated")))
#   define DEPRECATE_GDPUSHCHANNELDELEGATE __attribute__((deprecated("GDPushChannelDelegate protocol has been deprecated, use notifications instead.")))
#else
#   define DEPRECATE_PUSH_CONNECT_DISCONNECT __attribute__((deprecated))
#   define DEPRECATE_GDPUSHCONNECTION __attribute__((deprecated))
#   define DEPRECATE_GDPUSHCHANNELDELEGATE __attribute__((deprecated))
#endif
/* \endcond */

NS_ASSUME_NONNULL_BEGIN

/**
 * \ingroup pushchannelconstants
 * 
 * \{
 */

/** Push Channel state.
 * 
 * Use these enumerated constants to check the state of a Push Channel. The
 * \ss_pushchannel_link{state} property always takes one of these values.
 */
typedef NS_ENUM(NSInteger, GDPushChannelState)
{
    /** \copydetails ssPushChannelStateNone
     */
    GDPushChannelStateNone = 0,
    
    /** \copydetails ssPushChannelStateOpen
     */
    GDPushChannelStateOpen,
    
    /** \copydetails ssPushChannelStateClosed
     */
    GDPushChannelStateClosed,
    
    /** \copydetails ssPushChannelStateError
     */
    GDPushChannelStateError
};

/** Push Channel opened notification name.
 *
 * \copydetails ssPushChannelOpenNotification
 */
extern NSString* const GDPushChannelOpenedNotification;

/** Push Channel closed notification name.
 *
 * \copydetails ssPushChannelClosedNotification
 */
extern NSString* const GDPushChannelClosedNotification;

/** Push Channel error notification name.
 *
 * \copydetails ssPushChannelErrorNotification
 */
extern NSString* const GDPushChannelErrorNotification;

/** Push Channel received message notification name.
 *
 * \copydetails ssPushChannelMessageNotification
 */
extern NSString* const GDPushChannelMessageNotification;

/** Push Channel ping failed on server notification name.
 *
 * \copydetails ssPushChannelPingFailedNotification
 */
extern NSString* const GDPushChannelPingFailedNotification;

/** Key for the Push Channel token, in a notification user information
 *  dictionary.
 *
 * Use this constant to access the Push Channel token in a notification. The
 * token will be in the posted <tt>NSNotification</tt> instance, in the user
 * information dictionary, with this value as its key. It will be an
 * <tt>NSString</tt>.
 *
 * Example of usage:
 * \code
 * NSString *token = nsNotification.userInfo[GDPushChannelTokenKey];
 * \endcode
 *
 * The key will be present if the <tt>NSNotification</tt> has one of the
 * following values as its <tt>name</tt>.
 * - \ss_pushchannel_link{GDPushChannelOpenedNotification}.
 * - \ss_pushchannel_link{GDPushChannelClosedNotification}.
 * .
 */
extern NSString* const GDPushChannelTokenKey;

/** Key for the Push Channel host name, in a notification user information
 *  dictionary.
 *
 * Use this constant to get the host name of the push notification service in a notification. The
 * address will be in the posted <tt>NSNotification</tt> instance, in the user
 * information dictionary, with this value as its key. It will be an
 * <tt>NSString</tt>.
 *
 * Example of usage:
 * \code
 * NSString *pushServiceHostName = nsNotification.userInfo[GDPushChannelHostKey];
 * \endcode
 *
 * The key will be present if the <tt>NSNotification</tt> has the <tt>name</tt>:
 * \ss_pushchannel_link{GDPushChannelOpenedNotification}.
 */
extern NSString* const GDPushChannelHostKey;

/** Key for the message data, in a Push Channel notification user information
 *  dictionary.
 *
 * Use this constant to access the message data in a Push Channel notification.
 * The message will be in the posted <tt>NSNotification</tt> instance, in the
 * user information dictionary, with this value as its key. It will be an
 * <tt>NSString</tt>.
 *
 * Example of usage:
 * \code
 * NSString *message = nsNotification.userInfo[GDPushChannelMessageKey];
 * \endcode
 * 
 * The key will be present if the <tt>NSNotification</tt> has the <tt>name</tt>:
 * \ss_pushchannel_link{GDPushChannelMessageNotification}.
 */
extern NSString* const GDPushChannelMessageKey;

/** Key for the error code, in a Push Channel notification user information
 *  dictionary.
 *
 * Use this constant to access the error code in a Push Channel notification. The
 * code will be in the posted <tt>NSNotification</tt> instance, in the user
 * information dictionary, with this value as its key. It will be an
 * <tt>NSInteger</tt> value.
 *
 * Example of usage:
 * \code
 * NSInteger code = [nsNotification.userInfo[GDPushChannelErrorKey] integerValue];
 * \endcode
 *
 * The key will be present if the <tt>NSNotification</tt> has one of the
 * following values as its <tt>name</tt>.
 * - \ss_pushchannel_link{GDPushChannelErrorNotification}.
 * - \ss_pushchannel_link{GDPushChannelPingFailedNotification}.
 * .
 */
extern NSString* const GDPushChannelErrorKey;

/** \}
 */

/*!
 * \class GDPushChannel GDPush.h <BlackBerryDynamics/GD/GDPush.h>
 * \brief Manage Push Channel tokens and notifications.
 * 
 * \copydetails ssPushChannel
 */
@interface GDPushChannel : NSObject {
    @private
    void* m_pushChannelInternal;
}

/** Push Channel state.
 *
 * The BlackBerry Dynamics runtime sets this property to one of the
 * GDPushChannelState values to represent the state of the channel.
 * 
 * This property is compatible with key-value observing (KVO).
 */
@property (nonatomic, readonly) GDPushChannelState state;


/** Constructor that prepares a new Push Channel.
 *
 * \copydetails ssPushChannelConstructor
 */
- (instancetype)initWithIdentifier:(NSString*)pushChannelIdentifier;

/** Connect Push Channel.
 * 
 * \copydetails ssPushChannelConnect
 */
- (void)connect;

/** Disconnect Push Channel.
 * 
 * \copydetails ssPushChannelDisconnect
 */
- (void)disconnect;

@end

NS_ASSUME_NONNULL_END

#endif /* __GD_PUSH_H__ */
