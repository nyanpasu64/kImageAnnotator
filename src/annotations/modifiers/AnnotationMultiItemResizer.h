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

#ifndef ANNOTATIONMULTIITEMRESIZER_H
#define ANNOTATIONMULTIITEMRESIZER_H

#include <QGraphicsItemGroup>
#include <QGraphicsScene>

#include "AnnotationItemResizer.h"

class AnnotationMultiItemResizer : public QGraphicsItemGroup
{
public:
    explicit AnnotationMultiItemResizer();
    ~AnnotationMultiItemResizer() = default;
    virtual QRectF boundingRect() const override;
    void attachTo(QList<AbstractAnnotationItem*> items);
    void detach();
    void grabHandle(const QPointF& pos);
    void moveHandle(const QPointF& pos);
    void releaseHandle();
    bool isResizing() const;
    void refresh();
    bool hasItemsAttached() const;
    Qt::CursorShape cursorForPos(const QPointF &pos);
    Qt::CursorShape cursorForCurrentHandle();

private:
    QHash<AbstractAnnotationItem*, AnnotationItemResizer*> mItemToResizer;
    AnnotationItemResizer                                 *mCurrentResizer;

    AnnotationItemResizer* getResizerForItem(AbstractAnnotationItem* item);
};


#endif // ANNOTATIONMULTIITEMRESIZER_H
