/**
 *   判断是否连乘数字串函数
*    @param $strNum
 *   @return bool
 **/
function isExec($strNum) {
    $str = (string)$strNum;

    for ($i = 0; $i < strlen($str); $i++) {
        $k = 1;

        for ($j = $i + 1; $j < strlen($str); $j++) {

            $a_i = 0;
            $b_i = $i + 1;
            $p_i = $i + 1;
            $m_i = $k++;
            $c_i = $b_i + $m_i;
            $res = false;
            $formula = [];

            while (1) {
                $a = substr($str, $a_i, $p_i);
                $b = substr($str, $b_i, $m_i);

                $n = $a * $b;

                $c = substr($str, $c_i, strlen($n));

                //echo '<br/>' . $a . '*' . $b . '=' . $n . '->' . $c . '<br/>';

                if($c){
                    $formula[] = $a . '*' . $b . '=' . $n;
                }

                if ($c === false || $c === "") {
                    break;
                }

                if (intval($n) == intval($c)) {
                    $p_i = strlen($b);
                    $m_i = strlen($n);
                    $a_i = $b_i;
                    $b_i = $c_i;
                    $c_i = $b_i + $m_i;
                    $res = true;
                } else {
                    $res = false;
                    break;
                }
            }

            if ($res === true) {
                print_r($formula);
                return true;
            }

            //var_dump($res) . '<br/>';
        }

    }

    return false;
}

