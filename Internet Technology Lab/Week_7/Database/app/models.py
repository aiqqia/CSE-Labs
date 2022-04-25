from django.db import models
from django.core.validators import MinValueValidator
from django import forms

# Create your models here.
class Product(models.Model):
    id = models.AutoField(primary_key=True)
    title = models.CharField(max_length = 50)
    body = models.CharField(max_length = 200)
    price = models.IntegerField(validators = [MinValueValidator(0)])
    timestamp = models.DateTimeField()
    class Meta:
        ordering = ('-timestamp',)
    
class ProductForm(forms.ModelForm):
    class Meta:
        exclude = ('timestamp',)
        model = Product