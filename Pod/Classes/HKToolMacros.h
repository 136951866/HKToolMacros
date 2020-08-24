//
//  HKToolMacros.h
//  Takeaway
//
//  Created by hank on 2020/8/17.
//  Copyright © 2020 LZQ. All rights reserved.
//

#ifndef HKToolMacros_h
#define HKToolMacros_h


/** 定义block */
typedef void (^kHKBasicBlock)(void);
typedef void (^kHKBOOLBlock)(BOOL);
typedef void (^kHKIndexBlock)(NSInteger index);
typedef void (^kHKTextBlock)(NSString *str);
typedef void (^kHKObjBlock)(id object);
typedef void (^kHKFloatBlock)(CGFloat num);
typedef bool (^kHKReturnBlock)(void);
typedef void (^kHKDictionaryBlock)(NSDictionary *dic);
typedef void (^kHKArrBlock)(NSArray *);
typedef void (^kHKMutableArrBlock)(NSMutableArray *arr);
typedef void (^kHKViewBlock)(UIView *view);
typedef void (^kHKBtnBlock)(UIButton *btn);
typedef void (^kHKLblBlock)(UILabel *lable);
typedef void (^kHKDataBlock)(NSData *data);
typedef void (^kHKImgBlock)(UIImage *img);
typedef id (^ReturnObjectWithOtherObjectBlock)(id);
typedef void (^kHKIndexPathBlock)(NSIndexPath * indexpath);


/** 校验 */
//非空的NSNumber
#define kHKUnNilNumber(number) ([number isKindOfClass:[NSNumber class]]?number:@(0))
//字符串是否为空
#define kHKUnNilStr(str) ((str && ![str isEqual:[NSNull null]] && ![str isEqualToString:@"null"])?str:@"")
//判断字符串是否为空
#define kHKUnStrIsEmpty(str) ((str.length > 0 && ![str isKindOfClass:[NSNull class]]))
//非空的字符串 输出空格
#define kHKUnNilStrSpace(str) ((str && ![str isEqual:[NSNull null]] && ![str isEqualToString:@"(null)"])?str:@" ")
//整数转换成字符串
#define kHKStrWithInter(i) [NSString stringWithFormat:@"%@",@(i)]
//CGFloat转换成字符串
#define kHKStrWithFloat(f) [NSString stringWithFormat:@"%0.1f",f]
//数组是否为空
#define kHKUnArr(arr) ((arr && ![arr isEqual:[NSNull null]])?arr:nil)
//字典是否为空
#define kHKUnDic(dic) ((dic && ![dic isEqual:[NSNull null]])?dic:@{})
//是否是空对象
#define kHKUnObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
//验证字典有没有某个key 并且判断值的类型
#define kHKValidateDicWithKey(dic,key) ([dic objectForKey:key] && [dic objectForKey:key] != [NSNull null])
#define kHKValidateDicWithKey_Dic(dic,key) ([dic objectForKey:key] && [[dic objectForKey:key] isKindOfClass:[NSDictionary class]])
#define kHKValidateDicWithKey_Arr(dic,key) ([dic objectForKey:key] && [[dic objectForKey:key] isKindOfClass:[NSArray class]])
#define kHKValidateDicWithKey_Str(dic,key) ([dic objectForKey:key] && [[dic objectForKey:key] isKindOfClass:[NSString class]])



/** 弱强应用 */
#define kHKWEAKSELF typeof(self) __weak weakSelf = self;
#define kHKSTRONGSELF typeof(weakSelf) __strong strongSelf = weakSelf;


//block调用
#define kHKCallBlock(block, ...) if(block) block(__VA_ARGS__)


/** 屏幕比例 */
NS_INLINE CGFloat kHKFrameScaleX(){
    static CGFloat frameScaleX = 1.0;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        frameScaleX = SCREEN_WIDTH/375.0;
    });
    return frameScaleX;
}

NS_INLINE CGFloat kHKFrameScaleY(){
    static CGFloat frameScaleY = 1.0;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        frameScaleY = SCREEN_HEIGHT/667.0;
    });
    return frameScaleY;
}

#define kHKFitX(num)                 (kHKFrameScaleX() * (num))
#define kHKFitY(num)                 (kHKFrameScaleY() * (num))

/** 设备相关 */
NS_INLINE CGFloat device_version(){
    return [[[UIDevice currentDevice] systemVersion] doubleValue];
}
//系统版本

#define KHKIsiPhoneX \
({BOOL isPhoneX = NO; \
if (@available(iOS 11.0, *)) { \
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0; \
} \
(isPhoneX);})


#define  kMeStatusBarHeight      (KHKIsiPhoneX ? 44.f : 20.f)
#define  kMeNavigationBarHeight  44.f
#define  kMeTabBarHeight        (KHKIsiPhoneX ? (49.f+34.f) : 49.f)
#define  kMeTabbarSafeBottomMargin        (KHKIsiPhoneX ? 34.f : 0.f)
#define  kMeNavBarHeight  (KHKIsiPhoneX ? 88.f : 64.f)

//简化
/** 屏幕宽 */
#define kHKSCREEN_WIDTH    ([[UIScreen mainScreen] bounds].size.width)
#define kHKSCREEN_HEIGHT   ([[UIScreen mainScreen] bounds].size.height)
#define kHKApplicationHeight (kIsIOS7?CGRectGetHeight([UIScreen mainScreen].bounds):CGRectGetHeight([[UIScreen mainScreen] applicationFrame]))
/** 一些缩写 */
#define kHKAppDelegateInstance [[UIApplication sharedApplication] delegate]
#define kHKApplication        [UIApplication sharedApplication]
#define kHKKeyWindow          [UIApplication sharedApplication].keyWindow
#define kHKUserDefaults       [NSUserDefaults standardUserDefaults]
#define kHKNotificationCenter [NSNotificationCenter defaultCenter]
#define kHKFont(num) [UIFont systemFontOfSize:num]
#define kHKBOLD(x) [UIFont boldSystemFontOfSize:X(x)]
#define kHKFONTSTYLE(x,style) [UIFont fontWithName:style size:X(x)]

#define kHKAlterBtnTitle(title,msg,btnTitle) [[[UIAlertView alloc]initWithTitle:title message:msg delegate:nil cancelButtonTitle:btnTitle otherButtonTitles:nil, nil] show]
#define kHKAlter(title,msg)  kAlterBtnTitle(title,msg,@"关闭")
#define kHKGetAssetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define kHKCurrentWindow [[UIApplication sharedApplication].windows firstObject]
#define kHKSDLoadImg(class,url) [class sd_setImageWithURL:[NSURL URLWithString:url] placeholderImage:kImgPlaceholder]

#define kHKMaxX(view)      CGRectGetMaxX(view.frame)
#define kHKMaxY(view)      CGRectGetMaxY(view.frame)
#define kHKMidX(view)      CGRectGetMidX(view.frame)
#define kHKMidY(view)      CGRectGetMidY(view.frame)
#define kHKMinX(view)      CGRectGetMinX(view.frame)
#define kHKMinY(view)      CGRectGetMinY(view.frame)
#define kHKWidth(view)     CGRectGetWidth(view.frame)
#define kHKHeight(view)    CGRectGetHeight(view.frame)

#endif /* HKToolMacros_h */
