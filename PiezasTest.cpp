/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, Piezas) {
	Piezas piezas;
	ASSERT_EQ(piezas.pieceAt(0,1), Blank);
}

TEST(PiezasTest, reset) {
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.reset();
	ASSERT_EQ(piezas.pieceAt(2,0), Blank);
}

TEST(PiezasTest, dropPiece1) {
	Piezas piezas;
	ASSERT_EQ(piezas.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropPiece2) {
	Piezas piezas;
	ASSERT_EQ(piezas.dropPiece(-1), Invalid);
}

TEST(PiezasTest, dropPiece3) {
	Piezas piezas;
	ASSERT_EQ(piezas.dropPiece(1), X);
}

TEST(PiezasTest, dropPiece4) {
	Piezas piezas;
	piezas.dropPiece(2);
	ASSERT_EQ(piezas.dropPiece(1), O);
}

TEST(PiezasTest, pieceAt1) {
	Piezas piezas;
	piezas.dropPiece(2);
	ASSERT_EQ(piezas.pieceAt(2, 2), X);
}

TEST(PiezasTest, pieceAt2) {
	Piezas piezas;
	ASSERT_EQ(piezas.pieceAt(2, 2), Blank);
}

TEST(PiezasTest, pieceAt3) {
	Piezas piezas;
	ASSERT_EQ(piezas.pieceAt(5, 4), Invalid);
}

TEST(PiezasTest, gameState) {
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	ASSERT_EQ(piezas.gameState(), Invalid);
}

TEST(PiezasTest, gameStateX) {
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(3);
    ASSERT_EQ(piezas.gameState(),X);
}

TEST(PiezasTest, gameStateO) {
	Piezas piezas;
	piezas.dropPiece(0);
	piezas.dropPiece(0);
	piezas.dropPiece(1);
	piezas.dropPiece(1);
	piezas.dropPiece(2);
	piezas.dropPiece(2);
	piezas.dropPiece(0);
	piezas.dropPiece(3);
	piezas.dropPiece(1);
	piezas.dropPiece(3);
	piezas.dropPiece(3);
	piezas.dropPiece(2);
    ASSERT_EQ(piezas.gameState(), O);
}