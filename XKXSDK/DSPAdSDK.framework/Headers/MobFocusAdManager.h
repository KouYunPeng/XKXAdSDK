//
//  MobFocusAdManager.h
//  DSPAdSDK
//
//  Created by 寇云鹏 on 2019/8/5.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ConfigModel;
@class MobFocusAdManager;

NS_ASSUME_NONNULL_BEGIN

/**
 * 焦点图广告代理
 *
 * @protocol MobFocusAdManagerDelegate
 * @abstract 用户遵循焦点图广告代理，可以监听广告展示成功，失败，被曝光，被点击，详情页被关闭的方法
 */
@protocol MobFocusAdManagerDelegate <NSObject>

//========================↓↓↓↓ 代理方法开始 ↓↓↓↓========================

/**
 * 焦点图广告请求失败后调用
 *
 * @param error 焦点图广告错误信息
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 -1：侠客行自渲染 0：不存在 ）
 * @param focusAdManager 焦点图广告对象
 */
- (void)focusAdViewFailToReceived:(NSError *)error andType:(NSInteger)typeCode focusAdManager:(MobFocusAdManager *)focusAdManager;

/**
 * 焦点图广告被点击后调用
 *
 * @param focusAdManager 焦点图广告对象
 */
- (void)focusAdViewToClickedWhithFocusAdManager:(MobFocusAdManager *)focusAdManager;

/**
 * 焦点图广告被曝光时调用
 *
 * @param focusAdManager 焦点图广告对象
 */
- (void)focusViewToExposureWithFocusAdManager:(MobFocusAdManager *)focusAdManager;

/**
 * 焦点图广告详情页消失时调用
 *
 * @param focusAdManager 焦点图广告对象
 */
- (void)focusViewDidDismissLpWithFocusAdManager:(MobFocusAdManager *)focusAdManager;

/**
 * 焦点图广告加载成功时调用
 *
 * @param adView 需要展示的焦点图广告视图
 * @param typeCode 联盟第三方标识（1：百度 2：腾讯 3：穿山甲 -1：侠客行自渲染 0：不存在）
 * @param focusAdManager 焦点图广告对象
 */
- (void)focusViewExpressDataWithExpressAdView:(UIView *)adView andType:(NSInteger)typeCode focusAdManager:(MobFocusAdManager *)focusAdManager;

//========================↑↑↑↑ 代理方法结束 ↑↑↑↑========================

@end

/**
 * 焦点图广告类
 *
 * @class MobFocusAdManager
 * @abstract 用户初始化该类，可以创建焦点图广告，只支持上图下文显示，图片素材广告
 */
@interface MobFocusAdManager : NSObject

/** 焦点图广告对象的tag值 */
@property (nonatomic, assign)NSInteger tag;

/** 焦点图广告代理 */
@property (nonatomic, weak) id<MobFocusAdManagerDelegate> delegate;

//========================↓↓↓↓ 主动方法 ↓↓↓↓========================

/**
 * 根据参数配置模型初始化焦点图广告
 *
 * @param model 初始化时所需的参数配置模型
 */
- (instancetype)initFocusAdWithConfigModel:(XKXFocusAdModel *)model;

//========================↑↑↑↑ 主动方法 ↑↑↑↑========================

@end

NS_ASSUME_NONNULL_END
