from django.contrib import admin
from . import models

# Register your models here.
class ProductAdmin(admin.ModelAdmin):
    list_display = ('title','body','price','timestamp','id',)

admin.site.register(models.Product, ProductAdmin)
