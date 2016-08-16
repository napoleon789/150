<?php
/**
 * @file
 * sample_push.php
 *
 * Push demo
 *
 * LICENSE
 *
 * This source file is subject to the new BSD license that is bundled
 * with this package in the file LICENSE.txt.
 * It is also available through the world-wide-web at this URL:
 * http://code.google.com/p/apns-php/wiki/License
 * If you did not receive a copy of the license and are unable to
 * obtain it through the world-wide-web, please send an email
 * to aldo.armiento@gmail.com so we can send you a copy immediately.
 *
 * @author (C) 2010 Aldo Armiento (aldo.armiento@gmail.com)
 * @version $Id$
 */
function apns_sent_ms() {

// Adjust to your timezone
date_default_timezone_set('Asia/Hong_Kong');
  $giavang = doji_get_node('last');
   $hn_le_ban = $giavang->field_sjc_le_banra[0]['value'];
   $hn_le_mua = $giavang->field_sjc_le_muavao[0]['value'];
   $hcm_le_ban = $giavang->field_sjc_sg_le_banra[0]['value'];
   $hcm_le_mua = $giavang->field_sjc_sg_le_muavao[0]['value'];
  $time = date('h:i d/m/Y',$giavang->created - 3600);
  $tinnhan = $time. ' Vàng SJC: DOJI_HN '.$hn_le_ban.'/'.$hn_le_mua.'; DOJI_HCM: '.$hcm_le_ban.'/'.$hcm_le_mua;
// Report all PHP errors
error_reporting(-1);

// Using Autoload all classes are loaded on-demand
require_once 'ApnsPHP/Autoload.php';
// Instantiate a new ApnsPHP_Push object
$push = new ApnsPHP_Push(
	ApnsPHP_Abstract::ENVIRONMENT_SANDBOX,
	//'/var/www/giavang.doji.vn/public/ck.pem'
	'/var/www/giavang.doji.vn/public/sites/all/modules/custom/AppIphone/test/pushcert_dis.pem'
);

// Set the Provider Certificate passphrase
$push->setProviderCertificatePassphrase('123456');

// Set the Root Certificate Autority to verify the Apple remote peer
$push->setRootCertificationAuthority('/var/www/giavang.doji.vn/public/sites/all/modules/custom/AppIphone/test/pushcert_dis.pem');

// Connect to the Apple Push Notification Service
$push->connect();

// Instantiate a new Message with a single recipient
$result = db_query("SELECT DISTINCT devicetoken FROM {apns_devices}");
  while ($row = db_fetch_array($result)) {
    $token = $row['devicetoken'];

$message = new ApnsPHP_Message($token);

// Set a custom identifier. To get back this identifier use the getCustomIdentifier() method
// over a ApnsPHP_Message object retrieved with the getErrors() message.
$message->setCustomIdentifier("Message-Badge-1");

// Set badge icon to "3"
$message->setBadge(3);

// Set a simple welcome text
$message->setText($tinnhan);

// Play the default sound
$message->setSound();

// Set a custom property
$message->setCustomProperty('acme2', array('bang', 'whiz'));

// Set another custom property
$message->setCustomProperty('acme3', array('bing', 'bong'));

// Set the expiry value to 30 seconds
$message->setExpiry(30);

// Add the message to the message queue
$push->add($message);

// Send all messages in the message queue
$push->send();
  }

// Disconnect from the Apple Push Notification Service
$push->disconnect();

// Examine the error message container
$aErrorQueue = $push->getErrors();
if (!empty($aErrorQueue)) {
	var_dump($aErrorQueue);
}
}