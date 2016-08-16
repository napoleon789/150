
<div class="canhBaoTop" style=" " >
                    <ul>
 <?php foreach($content as $rows) : ?>
                        <li class="table wt-cb">
                            <div class="row" >{{datas.noidung}}</div>
                        </li>
                        <li class="table canhbao canhbao{{data.class}} "ng-repeat="data in datas "  rel={{data.id}} onclick = "popUpCanhBao();" on-finish-render="afterLoad()">
                            <div class="nd_loi table-left" >
                                <span class="lable"></span>
                                <div class="hienthi_row"  ng-click=Stop()>
                                    <div class="row" ng-repeat="noidung in data.noidung" >{{noidung}}</div>
                                </div>
                                <div class="hienthi_rowpoup"  ng-click=Start() style=" display:none;" >
                                    <div class="row_popup" ng-repeat="rows in data.ndpoup">
                                            <div class="title">{{rows.title}}</div>
                                        <div >
                                            <div ng-repeat="row in rows.error">{{row}}</div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                            <div class="table-right">{{data.time}}<div class="status{{data.class}}">{{data.status}}</div></div>
                        </li>
                      <?php  endforeach;?>
                    </ul>
                </div>