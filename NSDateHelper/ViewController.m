//
//  ViewController.m
//  NSDateHelper
//
//  Created by Nagam Pawan on 3/11/17.
//  Copyright © 2017 Nagam Pawan. All rights reserved.
//

#import "ViewController.h"

typedef enum dayType{
    
    Weekly,
    Monthly,
    Yearly
}dayType;
@interface ViewController (){
    
    dayType type;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    type = Monthly;
    self.currentDate = getDate([NSDate date]);
    
    // Do any additional setup after loading the view, typically from a nib.
}

-(void)viewWillAppear:(BOOL)animated{
    
    [super viewWillAppear:YES];
    [self setTitles];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)setTitles{
    
    NSString *dateString;
    if (type == Weekly) {
        
        dateString = getWeekDays(self.currentDate);
        
    }
    else if (type == Monthly){
        
        dateString = getMonthName(self.currentDate);
        
    }
    else if (type == Yearly){
        
        dateString = getYear(self.currentDate);
        
    }
    [self.buttonOutlet setTitle:dateString forState:UIControlStateNormal];
    
}

- (IBAction)button:(id)sender {
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Please select" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }];
    UIAlertAction *day = [UIAlertAction actionWithTitle:@"Weekly" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        type = Weekly;
        self.currentDate = getDate([NSDate date]);
        [self setTitles];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }];
    UIAlertAction *month = [UIAlertAction actionWithTitle:@"Monthly" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        type = Monthly;
        self.currentDate = getDate([NSDate date]);
        [self setTitles];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }];
    UIAlertAction *year = [UIAlertAction actionWithTitle:@"Yearly" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        type= Yearly;
        self.currentDate = getDate([NSDate date]);
        [self setTitles];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }];
    [alert addAction:cancel];
    [alert addAction:year];
    [alert addAction:month];
    [alert addAction:day];
 
    [self presentViewController:alert animated:YES completion:nil];
}
- (IBAction)next:(id)sender {
    
    if (type == Weekly) {
        
        self.currentDate = addDays(self.currentDate, 7);
        
    }
    
    else if (type == Monthly){
        
        self.currentDate = addMonth(self.currentDate, 1);
        
    }
    
    else if (type == Yearly){
        
        self.currentDate = addYear(self.currentDate, 1);
        
    }
    [self setTitles];
    
}

- (IBAction)previous:(id)sender {
    
    if (type == Weekly) {
        
        self.currentDate = addDays(self.currentDate, -7);
        
    }
    else if (type == Monthly){
        
        self.currentDate = addMonth(self.currentDate, -1);
        
    }
    else if (type == Yearly){
        
        self.currentDate = addYear(self.currentDate, -1);
        
    }
    [self setTitles];
}
@end
