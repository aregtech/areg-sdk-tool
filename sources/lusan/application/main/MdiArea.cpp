/************************************************************************
 *  This file is part of the Lusan project, an official component of the AREG SDK.
 *  Lusan is a graphical user interface (GUI) tool designed to support the development,
 *  debugging, and testing of applications built with the AREG Framework.
 *
 *  Lusan is available as free and open-source software under the MIT License,
 *  providing essential features for developers.
 *
 *  For detailed licensing terms, please refer to the LICENSE.txt file included
 *  with this distribution or contact us at info[at]aregtech.com.
 *
 *  \copyright   � 2023-2024 Aregtech UG. All rights reserved.
 *  \file        lusan/application/main/MdiArea.cpp
 *  \ingroup     Lusan - GUI Tool for AREG SDK
 *  \author      Artak Avetyan
 *  \brief       Lusan application MdiMainWindow setup.
 *
 ************************************************************************/

#include "lusan/application/main/MdiArea.hpp"
#include <QVBoxLayout>

MdiArea::MdiArea(QWidget* parent /*= nullptr*/)
    : QMdiArea(parent)
    // , mTabWidget(this)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    
    // mTabWidget.setTabPosition(QTabWidget::North);
    // Set the layout
    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(&mTabWidget);
    // setLayout(layout);
    setViewMode(ViewMode::TabbedView);
    showMaximized();
}
