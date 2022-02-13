function display1(display) {
    var a = display.value;
    var bar1 = document.getElementById('bar1')
    var bar2 = document.getElementById('bar2')
    var bar3 = document.getElementById('bar3')
    var bar4 = document.getElementById('bar4')
    var bar5 = document.getElementById('bar5')
    renderPage(a);
    switch (a) {
        case 1:
            document.getElementById('menu').setAttribute("style", "height:600px");
            bar1.style.background = "#e75b1e"
            bar2.style.background = "rgba(245, 245, 245, 1)"
            bar3.style.background = "rgba(245, 245, 245, 1)"
            bar4.style.background = "rgba(245, 245, 245, 1)"
            bar5.style.background = "rgba(245, 245, 245, 1)"

            break;
        case 2:
            document.getElementById('menu').setAttribute("style", "height:600px");
            bar2.style.background = "#e75b1e"
            bar1.style.background = "rgba(245, 245, 245, 1)"
            bar3.style.background = "rgba(245, 245, 245, 1)"
            bar4.style.background = "rgba(245, 245, 245, 1)"
            bar5.style.background = "rgba(245, 245, 245, 1)"
            break;
        case 3:
            document.getElementById('menu').setAttribute("style", "height:450px");
            bar3.style.background = "#e75b1e"
            bar2.style.background = "rgba(245, 245, 245, 1)"
            bar1.style.background = "rgba(245, 245, 245, 1)"
            bar4.style.background = "rgba(245, 245, 245, 1)"
            bar5.style.background = "rgba(245, 245, 245, 1)"
            break;
        case 4:
            document.getElementById('menu').setAttribute("style", "height:600px");
            bar4.style.background = "#e75b1e"
            bar2.style.background = "rgba(245, 245, 245, 1)"
            bar3.style.background = "rgba(245, 245, 245, 1)"
            bar1.style.background = "rgba(245, 245, 245, 1)"
            bar5.style.background = "rgba(245, 245, 245, 1)"

            break;
        case 5:
            document.getElementById('menu').setAttribute("style", "height:450px");
            bar5.style.background = "#e75b1e"
            bar2.style.background = "rgba(245, 245, 245, 1)"
            bar3.style.background = "rgba(245, 245, 245, 1)"
            bar4.style.background = "rgba(245, 245, 245, 1)"
            bar1.style.background = "rgba(245, 245, 245, 1)"
            break;
        default:
            break;
    }
}

function Pizza(name, price, describe, img, type) {
    this.name = name
    this.price = price
    this.describe = describe
    this.img = img
    this.type = type
}

function giohang(pizza, counter) {
    this.pizza = pizza;
    this.counter = counter;
}


var arrList = [
    new Pizza('Pizza Hải Sản', 120, 'gồm có: Tôm, phô mai, thịt và cua', './assets/img/pizzaHS.jpg', 1),
    new Pizza('Pizza Phô Mai', 120, 'Pizza phủ đầy sốt phô mai', './assets/img/pizzaPM.jpg', 1),
    new Pizza('Steak Tiêu Đen', 100, 'Steak kèm sốt tiêu đen đặc chế', './assets/img/steak2.jpg', 1),
    new Pizza('Steak Trứng', 80, 'Steak Trứng khoai tây ', './assets/img/steak.jpg', 1),
    new Pizza('Sushi Cá Hồi', 70, 'Cá Hồi từ đại dương', './assets/img/sushiCH.jpg', 1),
    new Pizza('Trà Sữa', 35, 'Trà thơm cùng với sữa tươi', './assets/img/TS.jpg', 1),
    new Pizza('Pizza Hải Sản', 120, 'gồm có: Tôm, phô mai, thịt và cua', './assets/img/pizzaHS.jpg', 2),
    new Pizza('Pizza Phô Mai', 120, 'Pizza phủ đầy sốt phô mai', './assets/img/pizzaPM.jpg', 2),
    new Pizza('Pizza Xúc Xích', 100, 'một món ngon đến từ pizza', './assets/img/PXX.jpg', 2),
    new Pizza('Pizza Rau Củ', 90, 'Pizza dành cho người thích rau củ', './assets/img/PizzaRauCu.jpg', 2),
    new Pizza('Pizza Thập Cẩm', 150, 'một món pizza đa dạng', './assets/img/pizzaTC.jpg', 2),
    new Pizza('Sushi Cá Hồi', 70, 'Cá Hồi từ đại dương', './assets/img/sushiCH.jpg', 3),
    new Pizza('Inari Sushi', 70, 'Totoro Inari Sushi dễ thương', './assets/img/sushiInari.jpg', 3),
    new Pizza('Gunkanmaki', 100, 'Sushi trứng cá hồi đại dương', './assets/img/gunSuShi.jpg', 3),
    new Pizza('Temari Sushi', 80, 'Sushi với hình thù đa dạng ', './assets/img/Tenmari.jpg', 3),
    new Pizza('Rump Steak', 120, 'Steak đùi thăn bò', './assets/img/rumpSteak.jpg', 4),
    new Pizza('STRIPLOIN STEAK', 120, 'Steak thăn lưng bò', './assets/img/stripSteak.jpg', 4),
    new Pizza('Steak Tiêu Đen', 100, 'Steak kèm sốt tiêu đen đặc chế', './assets/img/steak2.jpg', 4),
    new Pizza('Steak Trứng', 80, 'Steak Trứng khoai tây ', './assets/img/steak.jpg', 4),
    new Pizza('TENDERLOIN STEAK', 70, 'Steak Thăn chuột', './assets/img/tenderSteak.jpg', 4),
    new Pizza('Trà Sữa', 35, 'Trà thơm cùng với sữa tươi', './assets/img/TS.jpg', 5),
    new Pizza('Sinh Tố Bơ', 40, 'Pizza phủ đầy sốt phô mai', './assets/img/sinhToBo.jpg', 5),
    new Pizza('Nước Ép', 30, 'Steak kèm sốt tiêu đen đặc chế', './assets/img/nuocEp.jpg', 5),
    new Pizza('Trà Nóng', 80, 'Steak Trứng khoai tây ', './assets/img/tra.jpg', 5),
];

renderPage(1);
function renderPage(a) {
    const contain = document.getElementById("menu-list");
    var html = '';
    for (let i = 0; i < arrList.length; i++) {
        if (arrList[i].type == a) {
            html += ` 
            <div class="show-item show">
                <img src=${arrList[i].img} class="show-img">
            <div>
            <h3 class="show-name">${arrList[i].name}</h3>
            <p><i class="far fa-star"></i> Best seller <i class="far fa-star"></i></p>
            <p>${arrList[i].describe} </p>
            <input type="number" class="quantity" min="1" value="1">
            <br>
            <button class="show-btn" onclick="themVaoGioHang(${i})">Thêm vào giỏ</button>
            </div>
                <span class="price">${arrList[i].price}k</span class="price">
            </div>
        `;
        }
    }
    contain.innerHTML = html;
}

var gioHang = [];

function themVaoGioHang(i) {
    gioHang.push(arrList[i]);
}

function renderGioHang() {
    const gioHangContain = document.querySelector('#productList');
    var html = '';
    for (let i = 0; i < gioHang.length; i++) {
        html += `<div id="card-box">
                        <h4 id="card-name">${gioHang[i].name}</h4>
                        <input type="number" class="quantity" min="1" value=1 id="card-sl" onchange="thayDoiSoTien(${i},this)">
                        <h4 id="card-price" class="card_giohang_price">${gioHang[i].price}k</h4>
                    </div>`;
    }
    gioHangContain.innerHTML = html;
}

function thayDoiSoTien(i, obj) {
    const allPrice = document.querySelectorAll('#card-price');
    console.log(obj.value)
    allPrice[i].innerHTML = gioHang[i].price * parseInt(obj.value) + "k";
    getTongTien();
}

getTongTien();
function getTongTien() {
    const allPrice = document.querySelectorAll('#card-box .card_giohang_price');
    let sum = 0;
    for (let i = 0; i < allPrice.length; i++) {
        var str = allPrice[i].innerText;
        console.log(str);
        var price = parseInt(str.split("k")[0]);
        sum += price;
    }
    const tongtienText = document.querySelector('.modal-box-left .total_money span');
    tongtienText.innerText = sum + "k";
}

function Thanks() {
    if (getUserLogin() === undefined || getUserLogin() === "")
        alert("Quý khách cần đăng nhập để mua sản phẩm")
    else
        alert('Cảm ơn quý khách đã ủng hộ')
}

var login = false
if (click = 'dkyhtml') {
    login = true
}


function logout() {
    setUserLogin("");
}

function login_html() {
    if (getUserLogin() === undefined || getUserLogin() === "") {
        window.location = "login.html";
    }
    else {
        logout();
        alert("Đăng xuất thành công")
        location.reload();
    }
}

var pay_bar = document.getElementById('pay')
if (getUserLogin() === undefined || getUserLogin() === "") {
    setUserLogin("");
    const changeIcon = document.querySelectorAll(".btn i")[0];
    changeIcon.className = "user-icon fas fa-user";
    pay_bar.style.background = "#ccc"
    pay_bar.style.cursor = "auto"
}
else {
    const changeIcon = document.querySelectorAll(".btn i")[0];
    changeIcon.className = "user-icon fas fa-sign-out-alt";
    pay_bar.style.background = "#243b55"
    pay_bar.cursor = "pointer"
}

function getUserLogin() {
    return localStorage.isUserLogin;
}

function setUserLogin(username) {
    localStorage.isUserLogin = username;
}

