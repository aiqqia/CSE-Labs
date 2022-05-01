from django.shortcuts import render
from .models import Product, ProductForm

# Create your views here.
def home_view(request):
    return render(request, 'app/index.html', {'content':'Home Page'})

def index_view(request):
    pf = ProductForm(request.POST or None)
    if request.method == "POST":
        if pf.is_valid():
            nam = request.POST['name']
            eProd = Product.objects.filter(name=nam)[0]
            print(eProd)
            if eProd:
                if eProd.views:
                    eProd.views += 1
                else:
                    eProd.views = 1
                eProd.save()
                return render(request,'app/view.html',{'product':eProd})
            else:
                prod = pf.save(commit=False)
                if prod.views:
                    prod.views += 1
                else:
                    prod.views = 1
                prod.save()
                return render(request,'app/view.html',{'product':prod})
    return render(request, 'app/form.html', {'form':pf})