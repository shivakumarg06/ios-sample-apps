//
//  OOPlayerProtocol.h
//  OoyalaSDK
//
//  Created by Zhihui Chen on 7/31/14.
//  Copyright (c) 2014 Ooyala, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CMTimeRange.h>

/**
 * Defines different possible player states
 */
typedef enum
{
  /** Initial state, player is created but no content is loaded */
  OOOoyalaPlayerStateInit,
  /** Loading content */
  OOOoyalaPlayerStateLoading,
  /** Content is loaded and initialized, player is ready to begin playback */
  OOOoyalaPlayerStateReady,
  /** Player is playing a video */
  OOOoyalaPlayerStatePlaying,
  /** Player is paused, video is showing */
  OOOoyalaPlayerStatePaused,
  /** Player has finished playing content */
  OOOoyalaPlayerStateCompleted,
  /** Player has encountered an error, check OOOoyalaPlayer.error */
  OOOoyalaPlayerStateError
} OOOoyalaPlayerState;

@protocol OOPlayerProtocol<NSObject>

/**
 * @returns YES if the player will put its own controls on-screen;
 * NO if the player wants the Ooyala controls to be used instead.
 */
- (BOOL) hasCustomControls;

/**
 * This is called when pause is clicked
 */
- (void)pause;

/**
 * This is called when play is clicked
 */
- (void)play;

/**
 * This is called when stop is clicked
 */
- (void)stop;

/**
 * Get the current playhead time
 * @returns the current playhead time as CMTime
 */
- (Float64)playheadTime;

/**
 * Get the current item's duration
 * @returns duration as CMTime
 */
- (Float64)duration;

/**
 * Get the current item's buffer
 * @returns buffer as CMTimeRange
 */
- (Float64)buffer;

/**
 * Set the current playhead time of the player
 * @param[in] time CMTime to set the playhead time to
 */
- (void)seekToTime:(Float64)time;

/**
 * This returns the player state
 *
 * @return the state
 */
@property (nonatomic, readonly) OOOoyalaPlayerState state;
@property (nonatomic)           BOOL seekable;
@property (nonatomic, readonly) CMTimeRange seekableTimeRange;
@property (nonatomic)           BOOL allowsExternalPlayback;
@property (nonatomic, readonly) BOOL externalPlaybackActive;
@property (nonatomic)           float rate; // playback rate
@property (nonatomic, readonly) double bitrate;

@end
