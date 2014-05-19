//
// Created by MiKey on 11/27/13.
// Copyright (c) 2013 MapMyFitness Inc. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@interface MMDKWorkoutSequenceDO : NSManagedObject
@property(nonatomic, strong) NSNumber *minPW;
@property(nonatomic, strong) NSNumber *avgCD;
@property(nonatomic, strong) NSNumber *maxPace;
@property(nonatomic, strong) NSNumber *minHR;
@property(nonatomic, strong) NSNumber *maxCD;
@property(nonatomic, strong) NSNumber *stepCount;
@property(nonatomic, strong) NSNumber *workoutID;
@property(nonatomic, strong) NSNumber *avgSP;
@property(nonatomic, strong) NSNumber *avgPace;
@property(nonatomic, strong) NSNumber *avgPW;
@property(nonatomic, strong) NSNumber *totalDistance;
@property(nonatomic, strong) NSNumber *maxSP;
@property(nonatomic, strong) NSNumber *maxPW;
@property(nonatomic, strong) NSNumber *avgHR;
@property(nonatomic, strong) NSNumber *minCD;
@property(nonatomic, strong) NSNumber *maxHR;
@property(nonatomic, strong) NSNumber *minPace;
@property(nonatomic, strong) NSNumber *start_time;
@property(nonatomic, strong) NSNumber *minSP;
@property(nonatomic, strong) NSNumber *speedSource;
@property(nonatomic, strong) NSNumber *cadenceSource;
@property(nonatomic, strong) NSNumber *paceSource;
@property(nonatomic, strong) NSNumber *syncedWithServer;
@property(nonatomic, strong) NSNumber *totalSteps;
@property(nonatomic, strong) NSSet *sequenceData;

@end


@interface MMDKWorkoutSequenceDO (CoreDataGeneratedAccessors)
- (void)addSequenceDataObject:(MMDKWorkoutSequenceDO *)value;

- (void)removeSequenceDataObject:(MMDKWorkoutSequenceDO *)value;

- (void)addSequenceData:(NSSet *)value;

- (void)removeSequenceData:(NSSet *)value;
@end