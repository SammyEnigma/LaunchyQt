/*
Launchy: Application Launcher
Copyright (C) 2007-2009  Josh Karlin, Simon Capewell

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#pragma once

#include <QStyledItemDelegate>
#include <QLabel>

#define ROLE_SHORT Qt::DisplayRole
#define ROLE_FULL Qt::ToolTipRole
#define ROLE_ICON Qt::DecorationRole

namespace launchy {
class IconDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    IconDelegate(QObject *parent = 0);

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;

    virtual QSize sizeHint(const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

    void setColor(QString line, bool hi = false);

    void setFamily(QString fam);
    void setSize(int s);
    void setWeight(int w);
    void setItalics(int i);
    void setAlternativePathWidget(QLabel* label);

private:
    QColor m_color;
    QColor m_hiColor;
    QString m_family;
    int m_size;
    int m_weight;
    int italics;
    QLabel* m_alternativesPath;
};
}
