<?php

function _gold_management_login($email, $password) {
	$user = db_fetch_object(db_query("SELECT * FROM {users} WHERE mail = '%s' AND pass = '%s'", $email, md5($password)));
	if ($user) {
		$params = array(
			'success' => 1,
			'id' => $user->uid,
			'username' => $user->name,
			'sessionToken' => _gold_management_create_session_token($user->uid),
				);
	} else {
		$params = array(
				'success' => 0,
				'errorMsg' => "Wrong password",
				);
	}

	return $params;
}

function _gold_management_create_session_token($uid) {
	$date = date('Y-m');

	$str = $date . $uid . $date;

	return md5($str);
}

function _gold_management_register($username, $password, $email) {

  $query = db_query("SELECT * FROM {users} WHERE name ='%s' ",$username);
  $num = db_affected_rows($query);
  $query1 = db_query("SELECT * FROM {users} WHERE mail ='%s' ",$email);
  $num1 = db_affected_rows($query1);
  if($num1>0) {
  $params1 = array(
    'success' => 0,
    'error' => 'Email đã được sử dụng'
  );
  return $params1;
  }
  if($num > 0)
    $username = $username .' ';
  else
    $username = $username;
	$field = array(
			'name' => $username,
			'pass' => $password,
			'mail' => $email,
			'status' => 1
			);
	$account = user_save('', $field);

	drupal_mail('user', 'register_admin_created', $email, NULL, array('account' => $account), variable_get('site_mail', 'noreply@doji..com'));

	if ($account->uid) {
		$params = array(
			'success' => 1,
			'id' => $account->uid,
			'sessionToken' => _gold_management_create_session_token($account->uid),
		);
	} else {
		$params = array(
				'success' => 0,
                'error' => 'Email đã được sử dụng'
		);
	}

	return $params;
}

function _gold_management_verify_session($sessionToken, $uid) {
	$token = _gold_management_create_session_token($uid);

	if ($token == $sessionToken) {
		return TRUE;
	}

	return FALSE;
}

function _gold_management_add_transaction($gold_label, $date, $amount, $price, $uid) {
	$result = db_query("INSERT INTO {gold_management_transactions} (uid, gold_label, date, amount, price) VALUES (%d, '%s', '%s', %f, %f)", $uid, $gold_label, $date, $amount, $price);

	return $result;
}

function _gold_management_diadiem($tid) {
  $query = db_query("
    SELECT a.field_diadiem_phone_value, b.field_diadiem_diachi_value, c.field_diadiem_ten_value,
    d.field_diadiem_lat_value, e.field_diadiem_long_value
    FROM content_field_diadiem_phone a,content_field_diadiem_diachi b,content_field_diadiem_ten c,
    content_field_diadiem_lat d, content_field_diadiem_long e
    WHERE a.delta = b.delta and b.delta = c.delta and c.delta and c.delta = d.delta and d.delta = e.delta
    and e.delta in
    (SELECT delta from content_field_diadiem_city where field_diadiem_city_value ='%d' )",$tid
  );
  $address = array();
  while($result = db_fetch_array($query)) {
    array_push($address,$result);
  }
  return $address;
}