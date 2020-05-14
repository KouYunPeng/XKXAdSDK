//
//  MobNativeAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/3/11.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ConfigModel;
@class MobNativeAdManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * 信息流原生广告代理
 *
 * @protocol MobNativeAdManagerDelegate
 * @abstract 用户遵循信息流原生广告代理，可以监听到广告展示成功，失败，被曝光，被点击的方法。
 */
@protocol MobNativeAdManagerDelegate <NSObject>

//========================↓↓↓↓ 代理方法开始 ↓↓↓↓========================

/**
 * 信息流原生广告请求失败后调用
 *
 * @param error 信息流原生广告错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 -1：侠客行自渲染）
 * @param nativeAdManager 信息流原生广告对象
 */
- (void)nativeExpressViewFailToReceived:(NSError *)error andType:(NSInteger)typeCode nativeAdManager:(MobNativeAdManager *)nativeAdManager;

/**
 * 信息流原生广告被点击后调用
 *
 * @param nativeAdManager 信息流原生广告对象
 */
- (void)nativeExpressViewToClickedWhithNativeAdManager:(MobNativeAdManager *)nativeAdManager;

/**
 * 信息流原生广告栏曝光时调用
 *
 * @param nativeAdManager 信息流原生广告对象
 */
- (void)nativeExpressViewToExposureWithNativeAdManager:(MobNativeAdManager *)nativeAdManager;

/**
 * 信息流原生广告加载成功
 *
 * @param adViewsArr 加载成功的信息流原生广告视图数组
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 0：不存在 -1：侠客行自渲染）
 * @param nativeAdManager 信息流原生广告对象
 */
- (void)freshNativeExpressDataWithExpressAdViews:(NSMutableArray *)adViewsArr andType:(NSInteger)typeCode nativeAdManager:(MobNativeAdManager *)nativeAdManager;

//========================↑↑↑↑ 代理方法结束 ↑↑↑↑========================

@end


/**
 * 信息流原生广告类
 *
 * @class MobNativeAdManager
 * @abstract 用户初始化该类，可以创建信息流原生广告，支持广告上图下文格式的信息流
 */
@interface MobNativeAdManager : NSObject

/** 信息流原生广告对象的tag值 */
@property (nonatomic, assign)NSInteger tag;

/** 信息流原生广告代理 */
@property (nonatomic, weak) id<MobNativeAdManagerDelegate> delegate;

//========================↓↓↓↓ 主动方法 ↓↓↓↓========================

/**
 * 根据参数配置模型初始化信息流原生广告
 *
 * @param model 初始化时所需的参数配置模型
 */
- (instancetype)initNativeAdWithConfig:(XKXNativeAdModel *)model;

//========================↑↑↑↑ 主动方法 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
