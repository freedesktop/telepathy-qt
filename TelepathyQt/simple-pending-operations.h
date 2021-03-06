/**
 * This file is part of TelepathyQt
 *
 * @copyright Copyright (C) 2008-2009 Collabora Ltd. <http://www.collabora.co.uk/>
 * @copyright Copyright (C) 2008-2009 Nokia Corporation
 * @license LGPL 2.1
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

#ifndef _TelepathyQt_pending_operations_h_HEADER_GUARD_
#define _TelepathyQt_pending_operations_h_HEADER_GUARD_

#ifndef IN_TP_QT_HEADER
#error IN_TP_QT_HEADER
#endif

#include <QObject>

#include <TelepathyQt/PendingOperation>

namespace Tp
{

class TP_QT_EXPORT PendingSuccess : public PendingOperation
{
    Q_OBJECT
    Q_DISABLE_COPY(PendingSuccess)

public:
    PendingSuccess(const SharedPtr<RefCounted> &object)
        : PendingOperation(object)
    {
        setFinished();
    }
};

class TP_QT_EXPORT PendingFailure : public PendingOperation
{
    Q_OBJECT
    Q_DISABLE_COPY(PendingFailure)

public:
    PendingFailure(const QString &name, const QString &message,
            const SharedPtr<RefCounted> &object)
        : PendingOperation(object)
    {
        setFinishedWithError(name, message);
    }

    PendingFailure(const QDBusError &error,
            const SharedPtr<RefCounted> &object)
        : PendingOperation(object)
    {
        setFinishedWithError(error);
    }
};

class TP_QT_EXPORT PendingVoid : public PendingOperation
{
    Q_OBJECT
    Q_DISABLE_COPY(PendingVoid)

public:
    PendingVoid(QDBusPendingCall call, const SharedPtr<RefCounted> &object);

private Q_SLOTS:
    TP_QT_NO_EXPORT void watcherFinished(QDBusPendingCallWatcher*);

private:
    struct Private;
    friend struct Private;
    Private *mPriv;
};

class TP_QT_EXPORT PendingComposite : public PendingOperation
{
    Q_OBJECT
    Q_DISABLE_COPY(PendingComposite)

public:
    PendingComposite(const QList<PendingOperation*> &operations, const SharedPtr<RefCounted> &object);
    PendingComposite(const QList<PendingOperation*> &operations, bool failOnFirstError,
            const SharedPtr<RefCounted> &object);
    ~PendingComposite() override ;

private Q_SLOTS:
    TP_QT_NO_EXPORT void onOperationFinished(Tp::PendingOperation *);

private:
    struct Private;
    friend struct Private;
    Private *mPriv;
};

} // Tp

#endif
