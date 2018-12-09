/*
    Laser, a UCI chess engine written in C++11.
    Copyright 2015-2018 Jeffrey An and Michael An

    Laser is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Laser is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Laser.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SEARCHPARAMS_H__
#define __SEARCHPARAMS_H__

#include "common.h"

struct SearchParameters {
    int ply{};
    int selectiveDepth{};
    Move killers[MAX_DEPTH][2]{};
    int historyTable[2][6][64]{};
    int captureHistory[2][6][6][64]{};
    int **counterMoveHistory[6][64]{};
    int **followupMoveHistory[6][64]{};

    SearchParameters() {
        for (auto &i : counterMoveHistory) {
            for (int j = 0; j < 64; j++) {
                i[j] = new int *[6];
                for (int k = 0; k < 6; k++) {
                    i[j][k] = new int[64];
                }
            }
        }
        for (auto &i : followupMoveHistory) {
            for (int j = 0; j < 64; j++) {
                i[j] = new int *[6];
                for (int k = 0; k < 6; k++) {
                    i[j][k] = new int[64];
                }
            }
        }
        reset();
        resetHistoryTable();
    }

    ~SearchParameters() {
        for (auto &i : counterMoveHistory) {
            for (int j = 0; j < 64; j++) {
                for (int k = 0; k < 6; k++) {
                    delete[] i[j][k];
                }
                delete[] i[j];
            }
        }
        for (auto &i : followupMoveHistory) {
            for (int j = 0; j < 64; j++) {
                for (int k = 0; k < 6; k++) {
                    delete[] i[j][k];
                }
                delete[] i[j];
            }
        }
    }

    void reset() {
        ply = 0;
        for (auto &killer : killers) {
            killer[0] = NULL_MOVE;
            killer[1] = NULL_MOVE;
        }
    }

    void resetHistoryTable() {
        for (auto &i : historyTable) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 64; k++)
                    i[j][k] = 0;
            }
        }

        for (auto &i : captureHistory) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    for (int l = 0; l < 64; l++)
                        i[j][k][l] = 0;
                }
            }
        }

        for (auto &i : counterMoveHistory) {
            for (int j = 0; j < 64; j++) {
                for (int k = 0; k < 6; k++) {
                    for (int l = 0; l < 64; l++)
                        i[j][k][l] = 0;
                }
            }
        }

        for (auto &i : followupMoveHistory) {
            for (int j = 0; j < 64; j++) {
                for (int k = 0; k < 6; k++) {
                    for (int l = 0; l < 64; l++)
                        i[j][k][l] = 0;
                }
            }
        }
    }
};

#endif