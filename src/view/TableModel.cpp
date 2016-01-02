/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "TableModel.hpp"

typedef QModelIndex Index;

TableModel::TableModel(QObject* parent,
                       const GameDeskProxy* desk,
                       bool hostile):
    QAbstractTableModel(parent), desk_(desk),
    hostile_(hostile) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return desk_->getWidth();
}

int TableModel::columnCount(
    const Index& /*parent*/) const {
    return desk_->getLength();
}

QVariant TableModel::data(const Index& index,
                          int role) const {
    if (role == Qt::DecorationRole) {
        Point pt(index.column(), index.row());
        int pn = desk_->getPlayerNumber();
        // Enemy's number
        int en = 3 - pn;
        if (hostile_) {
            if (desk_->getVisibility(pt, en)) {
                if (desk_->getFlooding(pt, en)) {
                    return QImage(":/images/sunken_ship"
                                  ".png");
                } else if (desk_->getCellState(pt, en)) {
                    return QImage(":/images/burning_ship"
                                  ".png");
                } else {
                    return QImage(":/images/water.png");
                }
            } else {
                return QImage(":/images/not_visible.png");
            }
        } else {
            if (desk_->getFlooding(pt, pn)) {
                return QImage(":/images/sunken_ship.png");
            } else if (desk_->getCellState(pt, pn)) {
                if (desk_->getVisibility(pt, pn)) {
                    return QImage(":/images/burning_ship"
                                  ".png");
                } else {
                    return QImage(":/images/ship.png");
                }
            } else {
                if (desk_->getVisibility(pt, pn)) {
                    return QImage(":/images/water.png");
                } else {
                    return QImage(":/images/not_visible"
                                  ".png");
                }
            }
        }
    }
    return QVariant();
}

void TableModel::updateData() {
    reset();
}
