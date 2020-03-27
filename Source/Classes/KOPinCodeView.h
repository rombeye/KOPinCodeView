
#import <UIKit/UIKit.h>

//View Default: kCircle
typedef enum FormView : NSUInteger {
    kCircle,        //circle
    kFoursquare,    //Foursquare
    kNone,           //None
    kRombeye        //Custom Style
} FormView;

@protocol KOPinCodeViewDelegate <NSObject>
@required
/**
 delegate method. Called when entered all simbols.
 it returned symbols array and string with all symbols.
 
 @param symbolArray NSArray with NSString
 @param pin NSString
 */
- (void)pinDidEnterAllSymbol:(NSArray *)symbolArray string:(NSString*)pin;
@end

/**
 KOPinCodeView
 */
@interface KOPinCodeView : UIView
/**
 KOPinCodeViewDelegate
 */
@property (nonatomic, weak) IBOutlet id<KOPinCodeViewDelegate> delegate;
//Customized view settings
//------------------------------------------------------|
//---UIView---------------------------------------------|
//------------------------------------------------------|
//
@property (nonatomic) FormView formPinView;
//Thickness view line
@property (nonatomic) float lineDeep;
//Color view line
@property (nonatomic) UIColor *lineColor;
//Background color view in select state
@property (nonatomic) UIColor *selectColor;
//if pin codes did not matched, background view will highlight
@property (nonatomic) UIColor *notMatchColor;
//------------------------------------------------------|
//---UITextField----------------------------------------|
//------------------------------------------------------|
//Text color UITextField
@property (nonatomic) UIColor *symbolColor;
//Font UITextField
@property (nonatomic) UIFont *symbolFont;
//------------------------------------------------------|
//---Label----------------------------------------------|
//------------------------------------------------------|
//UILabel show only initPinViewWithConfirmPIN:
//Text color Label
@property (nonatomic) UIColor *titleColor;
//Font Label
@property (nonatomic) UIFont *titleFont;
//Text Label - Default: "enter Pin code"
@property (nonatomic) NSString *enterPinString;
//Text Label - Default: "Confirm Pin code"
@property (nonatomic) NSString *confirmPinString;
//------------------------------------------------------|
//---Other Setting--------------------------------------|
//------------------------------------------------------|
//Create Confirm Pin Code
@property (nonatomic) BOOL confirm;
//Secure Text - Default: YES
@property (nonatomic) BOOL secure;
//Keyboard Type
@property (nonatomic) UIKeyboardType typeKeyboard;
//------------------------------------------------------|
//---Methods--------------------------------------------|
//------------------------------------------------------|
/**
 init PinCodeView with cout symbol
 @param count int
 */
-(void)initPinWithCountView:(int)count;
/**
 init PinCodeView with confirm
 
 @param confirm BOOL value
 @param count int
 @param size CGSize
 @param form FormView type view
 */
-(void)initPinViewWithConfirmPIN:(BOOL)confirm
                     countSymbol:(int)count
                      sizeSimbol:(CGSize)size
                        formView:(FormView)form;

/**
 Become first cell
 */
-(void)becomeFirstCell;
// @AlphaApps: reset textFields function
-(void)clear;
// @AlphaApps: check if textFields are filled
@end
