<?php

function weather_info_get_weather($location, $language) {
  $requestAddress = sprintf('http://api.wunderground.com/api/8491fbbd87f98cc8/conditions/%s/q/%s.xml', $language, url($location));
  try {
    $xml_str = utf8_encode(file_get_contents($requestAddress, 0));
    $weather = new SimplexmlElement($xml_str);

    if (isset($weather->error->description)) {
      throw new Exception (t("Can't load %loc", array('%loc' => $location)));
    }

    if(!$weather) {
      throw new Exception('weather failed');
    }
  } catch (Exception $err) {
    watchdog('weather_info', 'Cannot get weather for %location: %message', array('%location' => $location, '%message' => $err->getMessage()), WATCHDOG_ERROR);
    return null;
  }

  return $weather;
}

function weather_info_temp($in_temp, $unit, $unit_system) {
  return sprintf('%s&deg;%a', $in_temp, $unit);
}
