/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef RESIZEHANDLES_H
#define RESIZEHANDLES_H

#include <QRectF>
#include <QList>

#include "../items/AbstractAnnotationLine.h"
#include "../items/AbstractAnnotationRect.h"
#include "../../common/helper/CursorHelper.h"

class ResizeHandles
{
public:
    explicit ResizeHandles(int handleSize);
    void initHandles(AbstractAnnotationItem *item);
    void updateHandlesPosition();
    int indexOfHandleAt(const QPointF& pos) const;
    QList<QRectF> handles() const;
    QRectF handle(int index) const;
    Qt::CursorShape cursorForPos(const QPointF &pos) const;
    Qt::CursorShape cursorForHandle(int index) const;

private:
    AbstractAnnotationLine* mLineItem;
    AbstractAnnotationRect* mRectItem;
    int                     mHandleSize;
    QList<QRectF>           mHandles;
    QList<Qt::CursorShape>  mCursors;

    void addHandlesToList(int count);
    void addLineCursorsToList();
    void addRectCursorsToList();
    void updateCursors();
};

#endif // RESIZEHANDLES_H
