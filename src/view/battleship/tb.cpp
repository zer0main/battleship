/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2015 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#include "tb.h"

typedef QModelIndex Index;

TableModel::TableModel(QObject* parent) {
}

int TableModel::rowCount(const Index& /*parent*/) const {
    return 100;
}

int TableModel::columnCount(
        const Index& /*parent*/) const {
    return 100;
}

QVariant TableModel::data(const Index& index,
                          int role) const {
    if (role == Qt::DecorationRole) {
        return QIcon("image.png");
    }
    return QVariant();
}
