// Autogenerated from Pigeon (v9.2.5), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#import <Foundation/Foundation.h>

@protocol FlutterBinaryMessenger;
@protocol FlutterMessageCodec;
@class FlutterError;
@class FlutterStandardTypedData;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PigeonSensorPosition) {
  PigeonSensorPositionBack = 0,
  PigeonSensorPositionFront = 1,
  PigeonSensorPositionUnknown = 2,
};

/// Video recording quality, from [sd] to [uhd], with [highest] and [lowest] to
/// let the device choose the best/worst quality available.
/// [highest] is the default quality.
///
/// Qualities are defined like this:
/// [sd] < [hd] < [fhd] < [uhd]
typedef NS_ENUM(NSUInteger, VideoRecordingQuality) {
  VideoRecordingQualityLowest = 0,
  VideoRecordingQualitySd = 1,
  VideoRecordingQualityHd = 2,
  VideoRecordingQualityFhd = 3,
  VideoRecordingQualityUhd = 4,
  VideoRecordingQualityHighest = 5,
};

/// If the specified [VideoRecordingQuality] is not available on the device,
/// the [VideoRecordingQuality] will fallback to [higher] or [lower] quality.
/// [higher] is the default fallback strategy.
typedef NS_ENUM(NSUInteger, QualityFallbackStrategy) {
  QualityFallbackStrategyHigher = 0,
  QualityFallbackStrategyLower = 1,
};

typedef NS_ENUM(NSUInteger, CupertinoFileType) {
  CupertinoFileTypeQuickTimeMovie = 0,
  CupertinoFileTypeMpeg4 = 1,
  CupertinoFileTypeAppleM4V = 2,
  CupertinoFileTypeType3GPP = 3,
  CupertinoFileTypeType3GPP2 = 4,
};

typedef NS_ENUM(NSUInteger, CupertinoCodecType) {
  CupertinoCodecTypeH264 = 0,
  CupertinoCodecTypeHevc = 1,
  CupertinoCodecTypeHevcWithAlpha = 2,
  CupertinoCodecTypeJpeg = 3,
  CupertinoCodecTypeAppleProRes4444 = 4,
  CupertinoCodecTypeAppleProRes422 = 5,
  CupertinoCodecTypeAppleProRes422HQ = 6,
  CupertinoCodecTypeAppleProRes422LT = 7,
  CupertinoCodecTypeAppleProRes422Proxy = 8,
};

typedef NS_ENUM(NSUInteger, PigeonSensorType) {
  /// A built-in wide-angle camera.
  ///
  /// The wide angle sensor is the default sensor for iOS
  PigeonSensorTypeWideAngle = 0,
  /// A built-in camera with a shorter focal length than that of the wide-angle camera.
  PigeonSensorTypeUltraWideAngle = 1,
  /// A built-in camera device with a longer focal length than the wide-angle camera.
  PigeonSensorTypeTelephoto = 2,
  /// A device that consists of two cameras, one Infrared and one YUV.
  ///
  /// iOS only
  PigeonSensorTypeTrueDepth = 3,
  PigeonSensorTypeUnknown = 4,
};

typedef NS_ENUM(NSUInteger, CamerAwesomePermission) {
  CamerAwesomePermissionStorage = 0,
  CamerAwesomePermissionCamera = 1,
  CamerAwesomePermissionLocation = 2,
  CamerAwesomePermissionRecord_audio = 3,
};

typedef NS_ENUM(NSUInteger, AnalysisImageFormat) {
  AnalysisImageFormatYuv_420 = 0,
  AnalysisImageFormatBgra8888 = 1,
  AnalysisImageFormatJpeg = 2,
  AnalysisImageFormatNv21 = 3,
  AnalysisImageFormatUnknown = 4,
};

typedef NS_ENUM(NSUInteger, AnalysisRotation) {
  AnalysisRotationRotation0deg = 0,
  AnalysisRotationRotation90deg = 1,
  AnalysisRotationRotation180deg = 2,
  AnalysisRotationRotation270deg = 3,
};

@class PreviewSize;
@class ExifPreferences;
@class PigeonSensor;
@class VideoOptions;
@class AndroidVideoOptions;
@class CupertinoVideoOptions;
@class PigeonSensorTypeDevice;
@class AndroidFocusSettings;
@class PlaneWrapper;
@class CropRectWrapper;
@class AnalysisImageWrapper;

@interface PreviewSize : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithWidth:(NSNumber *)width
    height:(NSNumber *)height;
@property(nonatomic, strong) NSNumber * width;
@property(nonatomic, strong) NSNumber * height;
@end

@interface ExifPreferences : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithSaveGPSLocation:(NSNumber *)saveGPSLocation;
@property(nonatomic, strong) NSNumber * saveGPSLocation;
@end

@interface PigeonSensor : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithPosition:(PigeonSensorPosition)position
    type:(PigeonSensorType)type
    deviceId:(nullable NSString *)deviceId;
@property(nonatomic, assign) PigeonSensorPosition position;
@property(nonatomic, assign) PigeonSensorType type;
@property(nonatomic, copy, nullable) NSString * deviceId;
@end

/// Video recording options. Some of them are specific to each platform.
@interface VideoOptions : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithEnableAudio:(NSNumber *)enableAudio
    android:(nullable AndroidVideoOptions *)android
    ios:(nullable CupertinoVideoOptions *)ios;
/// Enable audio while video recording
@property(nonatomic, strong) NSNumber * enableAudio;
@property(nonatomic, strong, nullable) AndroidVideoOptions * android;
@property(nonatomic, strong, nullable) CupertinoVideoOptions * ios;
@end

@interface AndroidVideoOptions : NSObject
+ (instancetype)makeWithBitrate:(nullable NSNumber *)bitrate
    quality:(VideoRecordingQuality)quality
    fallbackStrategy:(QualityFallbackStrategy)fallbackStrategy;
/// The bitrate of the video recording. Only set it if a custom bitrate is
/// desired.
@property(nonatomic, strong, nullable) NSNumber * bitrate;
/// The quality of the video recording, defaults to [VideoRecordingQuality.highest].
@property(nonatomic, assign) VideoRecordingQuality quality;
@property(nonatomic, assign) QualityFallbackStrategy fallbackStrategy;
@end

@interface CupertinoVideoOptions : NSObject
+ (instancetype)makeWithFileType:(CupertinoFileType)fileType
    codec:(CupertinoCodecType)codec
    fps:(nullable NSNumber *)fps;
/// Specify video file type, defaults to [AVFileTypeQuickTimeMovie].
@property(nonatomic, assign) CupertinoFileType fileType;
/// Specify video codec, defaults to [AVVideoCodecTypeH264].
@property(nonatomic, assign) CupertinoCodecType codec;
/// Specify video fps, defaults to [30].
@property(nonatomic, strong, nullable) NSNumber * fps;
@end

@interface PigeonSensorTypeDevice : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithSensorType:(PigeonSensorType)sensorType
    name:(NSString *)name
    iso:(NSNumber *)iso
    flashAvailable:(NSNumber *)flashAvailable
    uid:(NSString *)uid;
@property(nonatomic, assign) PigeonSensorType sensorType;
/// A localized device name for display in the user interface.
@property(nonatomic, copy) NSString * name;
/// The current exposure ISO value.
@property(nonatomic, strong) NSNumber * iso;
/// A Boolean value that indicates whether the flash is currently available for use.
@property(nonatomic, strong) NSNumber * flashAvailable;
/// An identifier that uniquely identifies the device.
@property(nonatomic, copy) NSString * uid;
@end

@interface AndroidFocusSettings : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithAutoCancelDurationInMillis:(NSNumber *)autoCancelDurationInMillis;
/// The auto focus will be canceled after the given [autoCancelDurationInMillis].
/// If [autoCancelDurationInMillis] is equals to 0 (or less), the auto focus
/// will **not** be canceled. A manual `focusOnPoint` call will be needed to
/// focus on an other point.
/// Minimal duration of [autoCancelDurationInMillis] is 1000 ms. If set
/// between 0 (exclusive) and 1000 (exclusive), it will be raised to 1000.
@property(nonatomic, strong) NSNumber * autoCancelDurationInMillis;
@end

@interface PlaneWrapper : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithBytes:(FlutterStandardTypedData *)bytes
    bytesPerRow:(NSNumber *)bytesPerRow
    bytesPerPixel:(nullable NSNumber *)bytesPerPixel
    width:(nullable NSNumber *)width
    height:(nullable NSNumber *)height;
@property(nonatomic, strong) FlutterStandardTypedData * bytes;
@property(nonatomic, strong) NSNumber * bytesPerRow;
@property(nonatomic, strong, nullable) NSNumber * bytesPerPixel;
@property(nonatomic, strong, nullable) NSNumber * width;
@property(nonatomic, strong, nullable) NSNumber * height;
@end

@interface CropRectWrapper : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithLeft:(NSNumber *)left
    top:(NSNumber *)top
    width:(NSNumber *)width
    height:(NSNumber *)height;
@property(nonatomic, strong) NSNumber * left;
@property(nonatomic, strong) NSNumber * top;
@property(nonatomic, strong) NSNumber * width;
@property(nonatomic, strong) NSNumber * height;
@end

@interface AnalysisImageWrapper : NSObject
/// `init` unavailable to enforce nonnull fields, see the `make` class method.
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)makeWithFormat:(AnalysisImageFormat)format
    bytes:(nullable FlutterStandardTypedData *)bytes
    width:(NSNumber *)width
    height:(NSNumber *)height
    planes:(nullable NSArray<PlaneWrapper *> *)planes
    cropRect:(nullable CropRectWrapper *)cropRect
    rotation:(AnalysisRotation)rotation;
@property(nonatomic, assign) AnalysisImageFormat format;
@property(nonatomic, strong, nullable) FlutterStandardTypedData * bytes;
@property(nonatomic, strong) NSNumber * width;
@property(nonatomic, strong) NSNumber * height;
@property(nonatomic, strong, nullable) NSArray<PlaneWrapper *> * planes;
@property(nonatomic, strong, nullable) CropRectWrapper * cropRect;
@property(nonatomic, assign) AnalysisRotation rotation;
@end

/// The codec used by AnalysisImageUtils.
NSObject<FlutterMessageCodec> *AnalysisImageUtilsGetCodec(void);

@protocol AnalysisImageUtils
- (void)nv21toJpegNv21Image:(AnalysisImageWrapper *)nv21Image jpegQuality:(NSNumber *)jpegQuality completion:(void (^)(AnalysisImageWrapper *_Nullable, FlutterError *_Nullable))completion;
- (void)yuv420toJpegYuvImage:(AnalysisImageWrapper *)yuvImage jpegQuality:(NSNumber *)jpegQuality completion:(void (^)(AnalysisImageWrapper *_Nullable, FlutterError *_Nullable))completion;
- (void)yuv420toNv21YuvImage:(AnalysisImageWrapper *)yuvImage completion:(void (^)(AnalysisImageWrapper *_Nullable, FlutterError *_Nullable))completion;
- (void)bgra8888toJpegBgra8888image:(AnalysisImageWrapper *)bgra8888image jpegQuality:(NSNumber *)jpegQuality completion:(void (^)(AnalysisImageWrapper *_Nullable, FlutterError *_Nullable))completion;
@end

extern void AnalysisImageUtilsSetup(id<FlutterBinaryMessenger> binaryMessenger, NSObject<AnalysisImageUtils> *_Nullable api);

/// The codec used by CameraInterface.
NSObject<FlutterMessageCodec> *CameraInterfaceGetCodec(void);

@protocol CameraInterface
- (void)setupCameraSensors:(NSArray<PigeonSensor *> *)sensors aspectRatio:(NSString *)aspectRatio zoom:(NSNumber *)zoom mirrorFrontCamera:(NSNumber *)mirrorFrontCamera enablePhysicalButton:(NSNumber *)enablePhysicalButton flashMode:(NSString *)flashMode captureMode:(NSString *)captureMode enableImageStream:(NSNumber *)enableImageStream exifPreferences:(ExifPreferences *)exifPreferences videoOptions:(nullable VideoOptions *)videoOptions completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<NSString *> *)checkPermissionsPermissions:(NSArray<NSString *> *)permissions error:(FlutterError *_Nullable *_Nonnull)error;
/// Returns given [CamerAwesomePermission] list (as String). Location permission might be
/// refused but the app should still be able to run.
- (void)requestPermissionsSaveGpsLocation:(NSNumber *)saveGpsLocation completion:(void (^)(NSArray<NSString *> *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getPreviewTextureIdCameraPosition:(NSNumber *)cameraPosition error:(FlutterError *_Nullable *_Nonnull)error;
- (void)takePhotoSensors:(NSArray<PigeonSensor *> *)sensors paths:(NSArray<NSString *> *)paths completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
- (void)recordVideoSensors:(NSArray<PigeonSensor *> *)sensors paths:(NSArray<NSString *> *)paths completion:(void (^)(FlutterError *_Nullable))completion;
- (void)pauseVideoRecordingWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)resumeVideoRecordingWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)receivedImageFromStreamWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)stopRecordingVideoWithCompletion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PigeonSensorTypeDevice *> *)getFrontSensorsWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PigeonSensorTypeDevice *> *)getBackSensorsWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)startWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)stopWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setFlashModeMode:(NSString *)mode error:(FlutterError *_Nullable *_Nonnull)error;
- (void)handleAutoFocusWithError:(FlutterError *_Nullable *_Nonnull)error;
/// Starts auto focus on a point at ([x], [y]).
///
/// On Android, you can control after how much time you want to switch back
/// to passive focus mode with [androidFocusSettings].
- (void)focusOnPointPreviewSize:(PreviewSize *)previewSize x:(NSNumber *)x y:(NSNumber *)y androidFocusSettings:(nullable AndroidFocusSettings *)androidFocusSettings error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setZoomZoom:(NSNumber *)zoom error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setMirrorFrontCameraMirror:(NSNumber *)mirror error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setSensorSensors:(NSArray<PigeonSensor *> *)sensors error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setCorrectionBrightness:(NSNumber *)brightness error:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getMinZoomWithError:(FlutterError *_Nullable *_Nonnull)error;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)getMaxZoomWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setCaptureModeMode:(NSString *)mode error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setRecordingAudioModeEnableAudio:(NSNumber *)enableAudio completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSArray<PreviewSize *> *)availableSizesWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)refreshWithError:(FlutterError *_Nullable *_Nonnull)error;
- (nullable PreviewSize *)getEffectivPreviewSizeIndex:(NSNumber *)index error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setPhotoSizeSize:(PreviewSize *)size error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setPreviewSizeSize:(PreviewSize *)size error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setAspectRatioAspectRatio:(NSString *)aspectRatio error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setupImageAnalysisStreamFormat:(NSString *)format width:(NSNumber *)width maxFramesPerSecond:(nullable NSNumber *)maxFramesPerSecond autoStart:(NSNumber *)autoStart error:(FlutterError *_Nullable *_Nonnull)error;
- (void)setExifPreferencesExifPreferences:(ExifPreferences *)exifPreferences completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
- (void)startAnalysisWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)stopAnalysisWithError:(FlutterError *_Nullable *_Nonnull)error;
- (void)setFilterMatrix:(NSArray<NSNumber *> *)matrix error:(FlutterError *_Nullable *_Nonnull)error;
- (void)isVideoRecordingAndImageAnalysisSupportedSensor:(PigeonSensorPosition)sensor completion:(void (^)(NSNumber *_Nullable, FlutterError *_Nullable))completion;
/// @return `nil` only when `error != nil`.
- (nullable NSNumber *)isMultiCamSupportedWithError:(FlutterError *_Nullable *_Nonnull)error;
@end

extern void CameraInterfaceSetup(id<FlutterBinaryMessenger> binaryMessenger, NSObject<CameraInterface> *_Nullable api);

NS_ASSUME_NONNULL_END
