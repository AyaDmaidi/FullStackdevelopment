import React from "react";
import { Link } from "react-router-dom";
import Rating from "../components/Rating";
import data  from "../data";
export default function ProductScreen(props){
    {/* find an element based on the criteria defined*/ }
    {/* comparing element id  in the products array with the value user enter in the route ( product/:id)*/}
    const product=data.products.find(x=>x._id===props.match.params.id);
    {/*if product does not found return product does not found*/ }
    if(!product){
        return <div>Product Not Found</div>
    }

{/*if product exist */}

return(
<div>
    {/* (/) is the home screen*/ }
    <a   href="/"> Back To Result  </a>

<div className="row top ">
{/*images*/ }
<div className="col-2">
<img  className="large"    src={product.Image} alt={product.name}></img>

</div>

{/*Description*/ }
<div className="col-1">
{/* unordered list*/ }

<ul  >
    <li> <h1>{product.name}</h1></li>
        {/* first element the name of product*/ }
       
    
 {/* second element the rating of product and number of reviews*/ }
    <li>
<Rating rating={product.rating} numReviews={product.numReviews}></Rating>
    </li>
 {/* third  element the price of product*/ }

    <li>
price:${product.price}
    </li>
 {/* fourth  element the description of product*/ }

<li>
    {/* paragraph for description*/ }
    Description:<p>{product.description}</p>
</li>
</ul>


</div>


{/*Action Part (user need to click on add to cart*/ }
<div className="col-1">
{/*because we want to create borders we put div*/ }

    <div className="card card-body">

<ul className="list">
    <li>
        <div className="row">

            <div >Price</div>
            <div className="price">${product.price}</div>
        </div>
    </li>

    <li>
        <div className="row">

            <div >Status</div>
            <div >
                {/*to show the negative case I put the (:) with span*/ }
                {product.countInStock>0?( <span className="success"> In Stock</span>):(
                <span className="error" > Unavailable</span>
                )}
            </div>
        </div>
    </li>
    {/*Button*/ }
    <li>
<button className="primary block ">Add to cart </button>
    </li>

</ul>

    </div>
</div>



</div>
</div>





    )}