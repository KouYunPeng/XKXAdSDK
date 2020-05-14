//
//  MobNativeVideoAdManager
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/9/3.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ConfigModel;
@class TemplateView;
@class MobNativeTemplateAdManager;

NS_ASSUME_NONNULL_BEGIN

/** 信息流广告视频状态枚举（针对视频素材） */
typedef NS_ENUM(NSInteger, VideoStatus) {
    VideoStatusPlay = 0, // 信息流视频播放
    VideoStatusPause,    // 信息流视频暂停
    VideoStatusStop,     // 信息流视频停止播放，并展示第一帧
    VideoStatusFinished  // 信息流视频播放完成
};



/**
 * 信息流广告代理
 *
 * @protocol MobNativeTemplateAdManagerDelegate
 * @abstract 用户遵循信息流广告代理，可以监听到广告展示成功，失败，被曝光，被点击，被关闭，以及视频广告播放状态被改变的方法。
 */
@protocol MobNativeTemplateAdManagerDelegate <NSObject>

//========================↓↓↓↓ 代理方法开始 ↓↓↓↓========================

/**
 * 信息流广告请求数据失败后调用
 *
 * @param error 信息流错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 -1：侠客行自渲染）
 * @param nativeAdManager 信息流广告对象
 */
- (void)nativeExpressViewFailToReceived:(NSError *)error andType:(NSInteger)typeCode nativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 *  信息流广告栏被点击后调用
 *
 *  @param nativeAdManager 模板信息流广告对象
 */
- (void)nativeExpressViewToClickedWhithNativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 *  信息流广告栏曝光时调用
 *
 *  @param nativeAdManager 模板信息流广告对象
 */
- (void)nativeExpressViewToExposureWithNativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 *  信息流广告被关闭时调用
 *
 *  @param expressView 模板信息流广告视图
 *  @param nativeAdManager 模板信息流广告对象
 */
- (void)nativeExpressViewToClosedWithExpressView:(UIView *)expressView andNativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 * 信息流广告详情页被关闭时调用
 *
 * @param nativeManager 模板信息流广告对象
 */
- (void)nativeExpressViewDidDismissLpWithNativeAdManager:(MobNativeTemplateAdManager *)nativeManager;

/**
 * 刷新获取信息流广告视图数组
 *
 * @param adViewsArr 需要展示的信息流广告视图数量
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 -1：侠客行自渲染）
 * @param nativeAdManager 信息流广告对象
 */
- (void)freshNativeExpressDataWithExpressAdViews:(NSMutableArray *)adViewsArr andType:(NSInteger)typeCode nativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 * 模板信息流广告视频素材被播放、暂停及停止时调用（只针对腾讯联盟广告）
 *
 * @param expressView 模板信息流广告视图
 * @param videoStatus 播放状态枚举 videoPlay播放 videoPause暂停 videoStop停止
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 -1：侠客行自渲染）
 * @param nativeAdManager 模板信息流广告对象
 */
- (void)nativeExpressAdOfVideoWithExpressView:(UIView *)expressView andChangedStatus:(VideoStatus)videoStatus andType:(NSInteger)typeCode andNativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

/**
 * 信息流模板广告渲染失败时调用
 *
 * @param failedView 模板信息流渲染失败的广告视图
 * @param nativeAdManager 模板信息流广告对象
 */
- (void)renderingFailedView:(UIView *)failedView andNativeAdManager:(MobNativeTemplateAdManager *)nativeAdManager;

//========================↑↑↑↑ 代理方法结束 ↑↑↑↑========================

@end


/**
 * 信息流广告类
 *
 * @class MobNativeVideoAdManager
 * @abstract 用户初始化该类，可以创建信息流广告，支持多条广告显示，支持视频素材及图片素材广告。
 */
@interface MobNativeTemplateAdManager : NSObject

/** 信息流模板广告对象的tag值 */
@property (nonatomic, assign)NSInteger tag;

/** 信息流模板广告代理 */
@property (nonatomic, weak) id<MobNativeTemplateAdManagerDelegate> delegate;

//========================↓↓↓↓ 主动方法 ↓↓↓↓========================

/**
 * 根据参数配置模型初始化信息流模板广告
 *
 * @param model 初始化时所需的参数配置模型
 */
- (instancetype)initNativeTemplateAdWithConfig:(XKXNativeTemplateAdModel *)model;

/**
 * 信息流视频素材广告，广告播放,暂停或停止（只针对腾讯联盟广告）
 *
 * @param view 需要播放的广告视图
 * @param videoStatus 播放状态 videoPlay播放 videoPause暂停 videoStop停止
 */
- (void)nativeTemplateAdOfVideoControlWithView:(UIView *)view andStatus:(VideoStatus)videoStatus;

/**
 * 控制器返回时执行的方法（处理联盟及自渲染广告的视图移除及对象释放操作）
 *
 * @param tempView 返回的信息流广告自定义视图
 */
- (void)removeAdWithView:(TemplateView *)tempView;

//========================↑↑↑↑ 主动方法 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
