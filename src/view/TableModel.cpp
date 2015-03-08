/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
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
        Point pt;
        // See Point.hpp
        pt.col = index.row();
        pt.row = index.column();
        int pn = desk_->getPlayerNumber();
        if (hostile_) {
            if (desk_->getVisibility(pt, pn)) {
                if (desk_->getFlooding(pt, pn)) {
                    return QIcon("sunken_ship.png");
                } else if (desk_->getCellState(pt, pn)) {
                    return QIcon("burning_ship.png");
                } else {
                    return QIcon("water.png");
                }
            } else {
                return QIcon("not_visible.png");
            }
        } else {
            if (desk_->getFlooding(pt, pn)) {
                return QIcon("sunken_ship.png");
            } else if (desk_->getCellState(pt, pn)) {
                if (desk_->getVisibility(pt, pn)) {
                    return QIcon("burning_ship.png");
                } else {
                    return QIcon("ship.png");
                }
            } else {
                return QIcon("water.png");
            }
        }
    }
    return QVariant();
}
