//
//  XKXNativeTemplateAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2020/2/3.
//  Copyright © 2020 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class XKXNativeTemplateAdManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * 信息流模板广告代理
 *
 * @protocol XKXNativeTemplateAdManagerDelegate
 * @abstract 用户遵循信息流模板广告代理，可以监听到广告展示成功，失败，被曝光，被点击，被关闭，以及视频广告播放状态被改变的方法。
 */
@protocol XKXNativeTemplateAdManagerDelegate <NSObject>

//========================↓↓↓↓ 代理方法开始 ↓↓↓↓========================

/**
 * 信息流模板广告请求数据失败后调用
 *
 * @param adType XKXADType类型 广告媒体类型
 * @param error 广告错误信息
 * @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdReceivedFaild:(XKXADType)adType error:(NSError *)error adManager:(XKXNativeTemplateAdManager *)manager;

/**
 * 信息流模板广告请求成功后调用
 *
 * @param adType XKXADType类型 广告媒体类型
 * @param adViews 信息里模板广告请求成功返回的信息流模板广告视图数组
 * @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdReceivedSuccessed:(XKXADType)adType adViews:(NSMutableArray *)adViews adManager:(XKXNativeTemplateAdManager *)manager;

/**
 *  信息流模板广告栏被点击后调用
 *
 *  @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdClickedWhithAdManager:(XKXNativeTemplateAdManager *)manager;

/**
 *  信息流模板广告栏曝光时调用
 *
 *  @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdExposureWithAdManager:(XKXNativeTemplateAdManager *)manager;

/**
 *  信息流模板广告被关闭时调用
 *
 *  @param expressView 信息流模板广告视图
 *  @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdClosedWithExpressView:(UIView *)expressView adManager:(XKXNativeTemplateAdManager *)manager;

/**
 * 信息流模板广告详情页被关闭时调用
 *
 * @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdDidDismissLpWithAdManager:(XKXNativeTemplateAdManager *)manager;

/**
 * 信息流模板广告视频素材被播放、暂停及停止时调用（只针对腾讯联盟广告）
 *
 * @param expressView 信息流模板广告视图
 * @param videoStatus 播放状态枚举 videoPlay播放 videoPause暂停 videoStop停止
 * @param adType XKXADType类型 广告媒体类型
 * @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdOfVideoWithExpressView:(UIView *)expressView changedStatus:(VideoStatus)videoStatus adType:(XKXADType)adType adManager:(XKXNativeTemplateAdManager *)manager;

/**
 * 信息流模板广告渲染失败时调用（只针对侠客行自渲染广告）
 *
 * @param failedView 信息流模板广告渲染失败的广告视图
 * @param manager 信息流模板广告对象
 */
- (void)xkxNativeTemplateAdRenderingFailedView:(UIView *)failedView adManager:(XKXNativeTemplateAdManager *)manager;

//========================↑↑↑↑ 代理方法结束 ↑↑↑↑========================

@end

/**
 * 信息流模板广告类
 *
 * @class XKXNativeTemplateAdManager
 * @abstract 用户初始化该类，可以创建信息流模板广告，支持多条广告显示，支持视频素材及图片素材广告。
 */
@interface XKXNativeTemplateAdManager : NSObject

//========================↓↓↓↓ 主动方法 ↓↓↓↓========================

/**
 * 根据参数配置模型及代理初始化信息流模板广告
 *
 * @param model 初始化时所需的参数模型
 * @param delegate weak类型 代理
 */
- (instancetype)initAndLoadAdWithConfig:(XKXNativeTempAdModel *)model
                               delegate:(id<XKXNativeTemplateAdManagerDelegate>)delegate;

//========================↑↑↑↑ 主动方法 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
