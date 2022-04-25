from django.shortcuts import render
from .models import Product, ProductForm
from datetime import datetime

# Create your views here.
def form_view(request):
    pf = ProductForm(request.POST or None)
    if request.method == 'POST':
        if pf.is_valid():
            product = pf.save(commit = False)
            product.timestamp = datetime.now()
            product.save()
            return render(request,'app/product.html',{'product':product})
    return render(request,'app/index.html',{'pf':pf})

def products_view(request):
    products = Product.objects.all()
    return render(request,'app/allproducts.html',{'products':products})