import React from 'react';
import {BrowserRouter , Route} from 'react-router-dom';
import HomeScreen from './screens/HomeScreen';
import ProductScreen from './screens/ProductScreen';

import { useDispatch, useSelector } from 'react-redux';
import { signout } from './actions/userActions';
const userSignin = useSelector((state) => state.userSignin);
  const { userInfo } = userSignin;
  const dispatch = useDispatch();
  const signoutHandler = () => {
    dispatch(signout());
  };
 </Link>
            {userInfo ? (
              <div className="dropdown">
                <Link to="#">
                  {userInfo.name} <i className="fa fa-caret-down"></i>{' '}
                </Link>
                <ul className="dropdown-content">
                  <li>
                    <Link to="#signout" onClick={signoutHandler}>
                      Sign Out
                    </Link>
                  </li>
                </ul>
              </div>
            ) : (
              <Link to="/signin">Sign In</Link>
            )} 

function App() {
  return (

    <BrowserRouter>
    <div  className="grid-container">
<header  className="row">
<div>
    <a className="brand"      href="/"> Bookie  </a>
</div>

<div>
<a href="cart.html">Cart</a>
<a href="/signin">Sign In</a>
</div>
</header>

<main>
<Route path="/product/:id" component={ProductScreen}></Route>
<Route path="/"  component={HomeScreen} exact></Route>


</main>
<footer   className="row center">All right reserved</footer>
</div>
</BrowserRouter>
  );
}

export default App;
