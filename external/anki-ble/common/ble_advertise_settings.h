/**
 * File: ble_advertise_settings.h
 *
 * Author: seichert
 * Created: 1/23/2018
 *
 * Description: Bluetooth Low Energy Advertising Settings
 *
 * Copyright: Anki, Inc. 2018
 *
 **/

#pragma once

#include "ble_advertise_data.h"

namespace Anki {

class BLEAdvertiseSettings {
 public:
  BLEAdvertiseSettings()
      : appearance_(0)
      , min_interval_(100)
      , max_interval_(1000)
  { }
  ~BLEAdvertiseSettings() = default;

  void SetAppearance(int appearance) { appearance_ = appearance; }
  int GetAppearance() const { return appearance_; }

  void SetMinInterval(int min_interval) { min_interval_ = min_interval; }
  int GetMinInterval() const { return min_interval_; }

  void SetMaxInterval(int max_interval) { max_interval_ = max_interval; }
  int GetMaxInterval() const { return max_interval_; }

  void SetAdvertisement(const BLEAdvertiseData& data) { advertisement_ = data; }
  const BLEAdvertiseData& GetAdvertisement() const { return advertisement_; }
  BLEAdvertiseData& GetAdvertisement() { return advertisement_; }

  void SetScanResponse(const BLEAdvertiseData& data) { scan_response_ = data; }
  const BLEAdvertiseData& GetScanResponse() const { return scan_response_; }
  BLEAdvertiseData& GetScanResponse() { return scan_response_; }

 private:
  int appearance_;
  int min_interval_;
  int max_interval_;
  BLEAdvertiseData advertisement_;
  BLEAdvertiseData scan_response_;
};

} // namespace Anki
