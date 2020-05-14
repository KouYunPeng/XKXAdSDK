//
//  TemplateView.h
//  DSPAdSDK
//
//  Created by 赵国成 on 2019/10/24.
//  Copyright © 2019 上海麒鎏信息科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
@class TemplateView;
@class MutedBtn;
NS_ASSUME_NONNULL_BEGIN

@protocol TemplateViewDelegate <NSObject>

- (void)sendVisibleImpressionWithBgView:(TemplateView *)bgView;

@end

/**
模板信息流广告视图类
该类只用于判断信息流广告素材是视频或者图片
*/
@interface TemplateView : UIView

@property (nonatomic, weak)id<TemplateViewDelegate> delegate;

@property (nonatomic, assign)BOOL isVideo; // 信息流广告素材类型  YES视频 NO非视频
@property (nonatomic, assign)BOOL isInScreen; // 信息流广告是否在手机屏幕中展示过 YES是 NO否
@property (nonatomic, weak)id manager; // 信息流广告对象，每个视图对应一个对象，处理上报曝光，视频信息流主动暂停、播放及停止的方法时使用
@property (nonatomic, weak)UIView *adView; // 广告视图
@property (nonatomic, weak)id object;//定义百度对象 曝光时使用
@property (nonatomic, weak)UIView *leftView ; // 广告视图
@property (nonatomic, weak)UIView *rightView; // 广告视图
@property (nonatomic, weak)UILabel *desTitleLab ; // 标题
@property (nonatomic, weak)MutedBtn *mutedBtn; // 音量按钮
@property (nonatomic, copy)NSString *tempAdDesc; // 广告描述
@property (nonatomic, copy)NSString *tempAdIconUrl; // 广告图标url地址


@end

NS_ASSUME_NONNULL_END
