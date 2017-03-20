//
//  Header.h
//  NSDateHelper
//
//  Created by Nagam Pawan on 3/11/17.
//  Copyright © 2017 Nagam Pawan. All rights reserved.
//

#ifndef Header_h
#define Header_h

static NSDate *getDate(NSDate *date){
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    components.hour = 0;
    components.minute = 0;
    components.second = 0;
    return [calendar dateFromComponents:components];
    
}

static NSDate *setInitialDayForTheDate(NSDate *date){
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    components.day = 1;
    NSDate *newDate = [calendar dateFromComponents:components];
    return newDate;
    
}

static NSDate *addDays(NSDate *date, int numberOfDays){
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.day = numberOfDays;
    components.month = 0;
    components.year = 0;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
    
}

static NSDate *addMonth(NSDate *date, int numberOfMonths){
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.year = 0;
    components.month = numberOfMonths;
    components.day = 0;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
    
}

static NSDate *addYear(NSDate *date, int numberOfYears){
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    NSDate *newDate = [calendar dateFromComponents:components];
    components.year = numberOfYears;
    components.month = 0;
    components.day = 0;
    newDate = [calendar dateByAddingComponents:components toDate:newDate options:0];
    return newDate;
    
}

static NSString *getStringFromDate(NSDate *date){
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"dd-MM-YYYY"];
    return [formatter stringFromDate:date];
    
}

static NSString *getMonthName(NSDate *date){
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"MMMM"];
    NSString *dateString = [formatter stringFromDate:date];
    return dateString;
    
}

static NSString *getWeekDays(NSDate *date){
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"dd-MMM"];
    NSString *startDate = [formatter stringFromDate:date];
    NSDate *endDate = addDays(date, 7);
    NSString *endDateString = [formatter stringFromDate:endDate];
    NSString *name = [NSString stringWithFormat:@"%@-%@", startDate, endDateString];
    return name;
    
}

static NSString *getYear(NSDate *date){
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"YYYY"];
    NSString *yearString = [formatter stringFromDate:date];
    return yearString;
    
}
#endif /* Header_h */
