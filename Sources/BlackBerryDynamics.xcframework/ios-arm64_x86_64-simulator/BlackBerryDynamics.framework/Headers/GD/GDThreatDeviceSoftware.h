/*
* (c) 2020 BlackBerry Limited. All rights reserved.
*
*/

#import <Foundation/Foundation.h>
#import <BlackBerryDynamics/GD/GDThreat.h>

NS_ASSUME_NONNULL_BEGIN

@interface BBDThreatDeviceSoftware : BBDThreat

/**
 * Creates an instance of BBDThreatDeviceSoftware.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (BOOL)isDeviceOSRestricted;
- (BBDThreatLevel)getDeviceOSRisk;

- (BOOL)isDeviceModelRestricted;
- (BBDThreatLevel)getDeviceModelRisk;

- (BOOL)isDeviceManufacturerRestricted;
- (BBDThreatLevel)getDeviceManufacturerRisk;

@end

NS_ASSUME_NONNULL_END
