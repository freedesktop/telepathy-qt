/*
 * This file is part of TelepathyQt4
 *
 * Copyright (C) 2008 Collabora Ltd. <http://www.collabora.co.uk/>
 * Copyright (C) 2008 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TelepathyQt4_contact_manager_internal_h_HEADER_GUARD_
#define _TelepathyQt4_contact_manager_internal_h_HEADER_GUARD_

#include <TelepathyQt4/Types>
#include <TelepathyQt4/PendingOperation>

namespace Tp
{

class TELEPATHY_QT4_NO_EXPORT PendingContactManagerRemoveContactListGroup : public PendingOperation
{
    Q_OBJECT

public:
    PendingContactManagerRemoveContactListGroup(const ChannelPtr &channel,
            QObject *parent = 0);
    ~PendingContactManagerRemoveContactListGroup() {};

private Q_SLOTS:
    void onContactsRemoved(Tp::PendingOperation *);
    void onChannelClosed(Tp::PendingOperation *);

private:
    ChannelPtr mChannel;
};

} // Tp

#endif