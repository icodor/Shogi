//
//  ShogiBoard.h
//  ShogiKing
//
//  Created by Conner DiPaolo on 1/18/15.
//  Copyright (c) 2015 Conner DiPaolo. All rights reserved.
//

// FYI I call the person on the 'bottom' of the board "player" or "ally" in the code equally
// The player on the top of the board is the 'enemy'

#import <Foundation/Foundation.h>
#import "SpriteKit/SpriteKit.h"

#define EMPTY 0

#define PAWN 1
#define LANCE 2
#define SILVER 3
#define KNIGHT 4
#define BISHOP 5
#define ROOK 6
#define GOLD 7
#define KING 8

// promoted is original piece + 10
#define PAWNP 11
#define LANCEP 12
#define SILVERP 13
#define KNIGHTP 14
#define BISHOPP 15
#define ROOKP 16


@interface ShogiBoard : NSObject

@property (nonatomic) NSDictionary* numberToLetter;
@property (nonatomic) NSMutableArray* playerCaptures;
@property (nonatomic) NSMutableArray* enemyCaptures;
@property (nonatomic) bool GameOver;
@property (nonatomic) bool PlayerIsWinner;
@property (nonatomic) bool playerTurn;
@property (nonatomic) int evaluation;


// piece and board retrieval functions
// returns the correct macro'ed value for a piece. if index out of range returns 255
- (int) pieceAtRowI: (int) i ColumnJ: (int) j;
- (int) pieceAtRowI:(int)i ColumnJ:(int)j forBoard: (int[9][9]) board;
- (int**) returnBoard;

// moves of pieces
- (void) movePieceAtRow:(int)row column:(int)col toRow:(int)finalRow toColumn:(int)finalCol onBoard:(int[9][9])b promote:(bool)promotePiece;
- (void) movePieceAtRow: (int)row column: (int)col toRow: (int)finalRow toColumn: (int) finalCol promote: (bool)promotePiece;
- (NSArray*) possibleMovesOfPieceAtRow: (NSNumber*)row column: (NSNumber*) col;

// possible drops and drop functions
- (NSArray*) possibleDropsForPiece:(int)piece onBoard:(int[9][9])b forCaptures:(NSMutableArray*)caps;
- (NSArray*) possibleDropsForPiece:(int)piece;
- (void) dropPiece:(int)piece forCaptures:(NSMutableArray*)caps toRowI:(NSNumber*)row colJ:(NSNumber*)col;
- (void) dropPiece:(int)piece toRowI:(NSNumber*)row colJ:(NSNumber*)col;

// SpriteNode from piece number
- (SKSpriteNode* ) nodeFromPiece:(int)piece;

// init methods
- (id) initWithArray: (int[9][9]) pieces;
- (id) init;

// copy board
- (id) copyWithZone:(NSZone* ) zone;

// match board with other board
- (void) matchBoard: (ShogiBoard* ) board;

// static evaluation
- (NSNumber*) NSEvaluate; // return evaluate as NSNumber
- (int) evaluate; // sum all of static evaluation components
- (int) check; // is king in check
- (int) drops; // quality of drops
- (int) piecesOnBoard; // total allied pieces on board
- (int) promotions; // number & quality of promoted pieces
- (int) pawns; // number of pawns
- (int) bishopMove; // how many moves bishop can take
- (int) rookMove; // how many moves rook can take
- (int) kingProtect; // how many allied pieces are near king
- (int) lanceMoves; // can lance move into promote area
- (int) knightMoves; // can knight move? Can he capture?
// add more factors?


@end
