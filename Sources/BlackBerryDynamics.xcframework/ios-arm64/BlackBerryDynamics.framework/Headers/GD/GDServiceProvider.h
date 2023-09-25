/*
 * Copyright 2023 BlackBerry Limited. All rights reserved.
 *
 */

#pragma once

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <BlackBerryDynamics/GD/GDiOS.h>
#else
#import <BlackBerryDynamics/GD/GDMac.h>
#endif

#import <BlackBerryDynamics/GD/GDAppServer.h>
#import <BlackBerryDynamics/GD/GDServiceDetail.h>

NS_ASSUME_NONNULL_BEGIN

@class GDServiceDetail;

/*!
 * \class GDServiceProvider GDServiceProvider.h <BlackBerryDynamics/GD/GDServiceProvider.h>
 * \brief Service provider details.
 *
 * This class is used to return information about a service provider. See
 * \ss_servicediscovery_link. An instance of this class either represents a
 * front-end application, running on a mobile device or computer, or a back-end
 * server.
 *
 * \if iOS The information returned for an application could be used to send a
 * service request to the service provider using AppKinetics. See the
 * \ss_serviceoverview_link for details of the programming interface.
 * \endif
 *
 * The information returned for a server could be used to establish HTTP or TCP
 * socket communications with an instance of the server.
 */
@interface GDServiceProvider : NSObject

/** BlackBerry Dynamics entitlement identifier.
 *
 * BlackBerry Dynamics entitlement identifier of the service provider.
 */
@property (nonatomic, strong) NSString* identifier;

/** BlackBerry Dynamics entitlement version.
 *
 * BlackBerry Dynamics entitlement version of the service provider.
 */
@property (nonatomic, strong) NSString* version;

/** Display name.
 *
 * Display name of the service provider.
 */
@property (nonatomic, strong) NSString* name;

/** Native application identifier, if an application (use for the
 *  <tt>sendTo</tt> <tt>application</tt> parameter).
 *
 * Native application identifier of the service provider, if it is an
 * application. This is the value that would be passed as the
 * <tt>application</tt> parameter in a call to \reflink GDServiceClient::sendTo:withService:withVersion:withMethod:withParams:withAttachments:bringServiceToFront:requestID:error: sendTo (GDServiceClient) \endlink.
 */
@property (nullable, nonatomic, strong) NSString* address;

/** Application icon, if retrieved.
 *
 * Application icon of the service provider, if it is an application and an icon
 * has been uploaded by the developer, and the icon data has been retrieved.
 * Otherwise, <tt>nil</tt>.\ See also the <tt>iconPending</tt> property, below.
 */
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
@property (nullable, nonatomic, strong) UIImage* icon;
#else
@property (nullable, nonatomic, strong) NSImage* icon;
#endif

/** Flag for there being an application icon that hasn't yet been retrieved.
 *
 * Flag for whether there is an application icon that hasn't yet been retrieved.
 *
 * Check this property if the <tt>icon</tt> property is <tt>nil</tt>. If this
 * property is <tt>YES</tt> then there is an icon for the service provider that
 * hasn't yet been retrieved by the BlackBerry Dynamics runtime. A
 * \reflink GDAppEvent GDAppEvent \endlink with type <tt>GDAppEventServicesUpdate</tt> will
 * be dispatched when the icon has been retrieved.
 *
 * If the <tt>icon</tt> property is <tt>nil</tt>, and this property is <tt>NO</tt>, it
 * means that there is no application icon.
 */
@property (nonatomic, assign) BOOL iconPending;

/** Details of server instances.
 *
 * Collection of <tt>GDAppServer</tt> objects, each representing an instance of
 * a server that provides the service. If there is more than one then the
 * application should use a server selection algorithm, such as that outlined
 * under the Application Server Selection heading in the
 * \reflink GDiOS::getApplicationConfig getApplicationConfig (GDiOS) \endlink documentation.
 */
@property (nonatomic, strong) NSArray<GDAppServer *>* serverCluster;

/** Details of provided services.
 *
 * Collection of <tt>GDServiceDetail</tt> objects, each representing a provided
 * shared service.
 */
@property (nonatomic, strong) NSArray<GDServiceDetail *>* services;
@end

NS_ASSUME_NONNULL_END
