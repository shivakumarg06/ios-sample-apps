/**
 * @class      OOControlsViewController OOControlsViewController.h "OOControlsViewController.h"
 * @brief      OOControlsViewController
 * @details    OOControlsViewController.h in OoyalaSDK
 * @date       2/23/12
 * @copyright  Copyright (c) 2012 Ooyala, Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "OOUIProgressSlider.h"

@class OOOoyalaPlayer;

static const double CONTROLS_HIDE_TIMEOUT = 5.37;
@interface OOControlsViewController : UIViewController

@property (nonatomic, weak) id delegate;
@property (nonatomic, weak) OOOoyalaPlayer *player;
@property (nonatomic, weak) UIView *overlay;
@property (nonatomic) UIActivityIndicatorView *activityView;
@property (nonatomic) UIView *controls;
@property (nonatomic) bool isVisible;
@property (nonatomic) NSTimer *hideControlsTimer;

- (void)showControls;
- (void)hideControls;
- (void)syncUI;

//Hide and show the full screen button on the inline view
- (void)setFullScreenButtonShowing: (BOOL) isShowing;

- (void)setLiveSliderShowing:(BOOL) isShowing;

- (OOUIProgressSliderMode) sliderMode;

// Change the language of controls when close caption changed
- (void)changeButtonLanguage:(NSString*)language;

// Switch the gravity for full screen mode.
- (void)switchVideoGravity;

- (void)updateClosedCaptionsPosition;

// calculate and set visibility of CC button.
-(void)updateClosedCaptionsButton;

@end
