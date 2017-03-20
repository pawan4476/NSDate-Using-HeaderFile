//
//  ViewController.h
//  NSDateHelper
//
//  Created by Nagam Pawan on 3/11/17.
//  Copyright © 2017 Nagam Pawan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Helper.h"

@interface ViewController : UIViewController

@property (strong, nonatomic) NSDate *currentDate;
- (IBAction)button:(id)sender;

@property (strong, nonatomic) IBOutlet UIButton *buttonOutlet;
- (IBAction)next:(id)sender;
- (IBAction)previous:(id)sender;

@end

