/*
 * Copyright © 2024 BlackBerry Limited. All rights reserved.
 */

#import <UIKit/UIKit.h>

/*!
 * \class GTLauncherSettingsViewController GTLauncherSettingsViewController.h <BlackBerryDynamics/GD/GTLauncherSettingsViewController.h>
 * @brief BlackBerry Dynamics Launcher settings view controller.
 * 
 * This class represents the Launcher settings view controller class.
 * Host applications that choose to implement the delegate method
 * @code -[id <GTLauncherViewControllerDelegate> settingsViewControllerForLauncherViewController:] @endcode
 * and return their own settings view controller @b must make this
 * settings view controller accessible from within their settings
 * hierarchy.
 *
 * As an example, the host application's setting view controller is
 * a @p UINavigationController who's visible view controller
 * is a subclass of @p UITableViewController. One of the cells
 * of the latter controller has a selection behavior of pushing the
 * Launcher's settings view controller to the navigation stack.
 *
 * Applications that choose not to provide a custom settings view
 * controller may ignore this class as it will be presented automatically
 * when a user taps on the settings icon within Launcher.
 *
 * Use the standard @p init method to load the Launcher view controller.
 * Using @p initWithNibName:bundle: will throw an exception.
 *
 * \b Localization<br>
 * Because the term Launcher is a brand, references to it should
 * be made with an English-only translation.
 */
OBJC_EXPORT
@interface GTLauncherSettingsViewController : UIViewController

@end
