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

#include "AnnotationPropertiesFactory.h"

AnnotationProperties AnnotationPropertiesFactory::createProperties(ToolTypes type) const
{
    AnnotationProperties properties(mColor, mSize);
    if(type == ToolTypes::Arrow || type == ToolTypes::Number) {
        properties.setFillType(FillTypes::SameFill);
    } else {
        properties.setFillType(mFillType);
    }
    return properties;
}

void AnnotationPropertiesFactory::setColor(const QColor& color)
{
    mColor = color;
}

void AnnotationPropertiesFactory::setSize(int size)
{
    mSize = size;
}

void AnnotationPropertiesFactory::setFillType(FillTypes fillType)
{
    mFillType = fillType;
}
