/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "TransectStyleComplexItemTestBase.h"
#include "MultiSignalSpy.h"
#include "CorridorScanComplexItem.h"
#include "PlanMasterController.h"

#include <QGeoCoordinate>

class TestTransectStyleItem;

class TransectStyleComplexItemTest : public TransectStyleComplexItemTestBase
{
    Q_OBJECT
    
public:
    TransectStyleComplexItemTest(void);

protected:
    void init(void) final;
    void cleanup(void) final;

private slots:
    void _testDirty             (void);
    void _testRebuildTransects  (void);
    void _testDistanceSignalling(void);
    void _testAltMode           (void);
    void _testFollowTerrain     (void);

private:
    enum {
        // These signals are from TransectStyleComplexItem
        cameraShotsChangedIndex = 0,
        timeBetweenShotsChangedIndex,
        visualTransectPointsChangedIndex,
        coveredAreaChangedIndex,
        // These signals are from ComplexItem
        dirtyChangedIndex,
        complexDistanceChangedIndex,
        greatestDistanceToChangedIndex,
        additionalTimeDelayChangedIndex,
        // These signals are from VisualMissionItem
        lastSequenceNumberChangedIndex,
        maxSignalIndex
    };

    enum {
        // These signals are from TransectStyleComplexItem
        cameraShotsChangedMask =                1 << cameraShotsChangedIndex,
        timeBetweenShotsChangedMask =           1 << timeBetweenShotsChangedIndex,
        visualTransectPointsChangedMask =       1 << visualTransectPointsChangedIndex,
        coveredAreaChangedMask =                1 << coveredAreaChangedIndex,
        // These signals are from ComplexItem
        dirtyChangedMask =                      1 << dirtyChangedIndex,
        complexDistanceChangedMask =            1 << complexDistanceChangedIndex,
        greatestDistanceToChangedMask =         1 << greatestDistanceToChangedIndex,
        additionalTimeDelayChangedMask =        1 << additionalTimeDelayChangedIndex,
        // These signals are from VisualMissionItem
        lastSequenceNumberChangedMask =         1 << lastSequenceNumberChangedIndex,
    };

    static const size_t _cSignals = maxSignalIndex;
    const char*         _rgSignals[_cSignals];

    MultiSignalSpy*         _multiSpy =             nullptr;
    TestTransectStyleItem*  _transectStyleItem =    nullptr;
};

class TestTransectStyleItem : public TransectStyleComplexItem
{
    Q_OBJECT

public:
    TestTransectStyleItem(PlanMasterController* masterController, QObject* parent = nullptr);

    // Overrides from ComplexMissionItem
    QString patternName         (void) const final { return QString(); }
    QString mapVisualQML        (void) const final { return QString(); }
    bool    load                (const QJsonObject& complexObject, int sequenceNumber, QString& errorString) final { Q_UNUSED(complexObject); Q_UNUSED(sequenceNumber); Q_UNUSED(errorString); return false; }

    // Overrides from VisualMissionItem
    void    save                (QJsonArray&  missionItems) final { Q_UNUSED(missionItems); }
    bool    specifiesCoordinate (void) const final { return true; }
    double  additionalTimeDelay (void) const final { return 0; }

    bool rebuildTransectsPhase1Called;
    bool recalcComplexDistanceCalled;
    bool recalcCameraShotsCalled;
    void _adjustSurveAreaPolygon(void);
    QList<QList<CoordInfo_t>> transects() const {
        return _transects;
    }

private slots:
    // Overrides from TransectStyleComplexItem
    void _rebuildTransectsPhase1    (void) final;
    void _recalcCameraShots         (void) final;
};
