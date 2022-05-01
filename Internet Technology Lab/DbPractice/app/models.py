from django.db import models
from django import forms

# Create your models here.
class Product(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=100)
    price = models.IntegerField()
    views = models.IntegerField()

class ProductForm(forms.ModelForm):
    class Meta:
        model = Product
        exclude = ('views',)