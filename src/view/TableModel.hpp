/*
 * Battleship, classic battleship game
 * Copyright (C) 2014-2016 Pavel Dolgov
 *
 * See the LICENSE file for terms of use.
 */

#ifndef TABLE_MODEL_HPP_
#define TABLE_MODEL_HPP_

#include <QtGui>

#include "GameDeskProxy.hpp"

/** Model for QTableView */
class TableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    TableModel(QObject* parent,
               const GameDeskProxy* desk,
               bool hostile);

    int rowCount(const QModelIndex& parent =
                     QModelIndex()) const;

    int columnCount(const QModelIndex& parent =
                        QModelIndex()) const;

    QVariant data(const QModelIndex& index, int role =
                      Qt::DisplayRole) const;

    void updateData();

private:
    const GameDeskProxy* desk_;

    bool hostile_;
};

#endif
